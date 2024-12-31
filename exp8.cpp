#include <iostream>
#include <vector>
using namespace std;

// Function to generate primes using Sieve of Eratosthenes
vector<int> generatePrimes(int limit) {
    vector<bool> isPrime(limit + 1, true);
    vector<int> primes;
    isPrime[0] = isPrime[1] = false;
    for (int i = 2; i <= limit; i++) {
        if (isPrime[i]) {
            primes.push_back(i);
            for (int j = i * 2; j <= limit; j += i) {
                isPrime[j] = false;
            }
        }
    }
    return primes;
}

int main() {
    int T;
    cin >> T;

    // Generate primes up to 10^7 to handle large N
    const int MAX_PRIME = 10000000;
    vector<int> primes = generatePrimes(MAX_PRIME);

    while (T--) {
        long long N, K;
        cin >> N >> K;

        // Maximum possible co-prime pairs
        long long maxPairs = (N * (N - 1)) / 2;

        if (K > maxPairs) {
            cout << -1 << endl;
            continue;
        }

        vector<int> result(N);

        // Step 1: Initialize array with first N primes
        for (int i = 0; i < N; i++) {
            result[i] = primes[i];
        }

        // Step 2: Reduce pairs to match K
        long long currentPairs = maxPairs;
        for (int i = N - 1; i > 0 && currentPairs > K; i--) {
            long long reduceBy = N - 1 - i; // Pairs reduced by duplicating result[i]
            if (currentPairs - reduceBy >= K) {
                result[i] = result[i - 1]; // Duplicate previous element
                currentPairs -= reduceBy;
            } else {
                // Fine-tune to match K exactly
                result[i] = primes[i - (currentPairs - K)];
                currentPairs = K;
            }
        }

        // Output the result
        for (int i = 0; i < N; i++) {
            cout << result[i] << " ";
        }
        cout << endl;
    }

    return 0;
}
