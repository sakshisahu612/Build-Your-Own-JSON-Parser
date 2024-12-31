#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int calculateSmallIndices(int N, vector<int>& A, vector<int>& B) {
    // Two DP arrays for tracking small indices count
    vector<int> dpA(N + 1, 0);
    vector<int> dpB(N + 1, 0);
    
    // Iterate over elements starting from index 3
    for (int i = 3; i <= N; i++) {
        bool foundSmallIndex = false;

        // Check pairs (j, k) where 1 <= j < k < i
        for (int j = 1; j < i; j++) {
            for (int k = j + 1; k < i; k++) {
                // Check conditions for A[i-1] and B[i-1]
                if (A[i - 1] <= A[j - 1] + A[k - 1] || 
                    B[i - 1] <= B[j - 1] + B[k - 1] || 
                    A[i - 1] <= B[j - 1] + A[k - 1] || 
                    B[i - 1] <= A[j - 1] + B[k - 1]) {
                    
                    foundSmallIndex = true;
                    break;
                }
            }
            if (foundSmallIndex) break;
        }

        // Update DP arrays based on whether a small index was found
        if (foundSmallIndex) {
            dpA[i] = dpA[i - 1] + 1; // Count small index using A
            dpB[i] = dpB[i - 1];     // No new small index using B
        } else {
            dpA[i] = dpA[i - 1];     // No new small index using A
            dpB[i] = dpB[i - 1];     // No new small index using B
        }
    }

    // The result is the maximum between both DP arrays at N
    return max(dpA[N], dpB[N]);
}

int main() {
    int T;
    cin >> T;

    while (T--) {
        int N;
        cin >> N;

        vector<int> A(N), B(N);
        for (int i = 0; i < N; i++) cin >> A[i];
        for (int i = 0; i < N; i++) cin >> B[i];

        // Compute and output the maximum number of small indices
        cout << calculateSmallIndices(N, A, B) << endl;
    }

    return 0;
}