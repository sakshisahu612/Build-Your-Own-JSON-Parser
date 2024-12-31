#include <iostream>
#define MOD 1000000007

using namespace std;

long long modularExponentiation(long long base, long long exp, long long mod) {
    long long result = 1;
    while (exp > 0) {
        if (exp % 2 == 1) {
            result = (result * base) % mod;
        }
        base = (base * base) % mod;
        exp /= 2;
    }
    return result;
}

int main() {
    long long n;
    cin >> n;

    long long result = modularExponentiation(2, n, MOD);

    cout << result << endl;

    return 0;
}