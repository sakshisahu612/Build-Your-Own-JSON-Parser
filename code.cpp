#include<bits/stdc++.h>

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void longestSubsequence(int N, int K, vector<vector<int>>& A) {
    // Initialize a 2D vector to store the maximum length and corresponding starting
    // element for each index and increment value (multiple of K).
    vector<vector<pair<int, int>>> dp(N + 1, vector<pair<int, int>>(K + 1, {0, 0}));

    // Process queries in A to update the dp table.
    for (const vector<int>& query : A) {
        int L = query[0] - 1;  // Adjust for 0-based indexing
        int R = query[1] - 1;
        int X = query[2];

        for (int i = L; i <= R; ++i) {
            for (int j = 1; j <= K; ++j) {
                // Update dp[i + 1][j] if adding X at index i leads to a longer or
                // lexicographically smaller subsequence starting with a value that
                // is a multiple of K.
                int prevVal = (i == 0) ? 0 : dp[i][j].second + K;
                if (dp[i + 1][j].first < dp[i][j].first + 1 ||
                    (dp[i + 1][j].first == dp[i][j].first + 1 && prevVal < X)) {
                    dp[i + 1][j] = {dp[i][j].first + 1, X - prevVal};
                }
            }
        }
    }

    // Find the maximum length and corresponding increment value.
    int maxLength = 0, maxIncrement = 0;
    for (int j = 1; j <= K; ++j) {
        if (dp[N][j].first > maxLength) {
            maxLength = dp[N][j].first;
            maxIncrement = j;
        }
    }

    // Reconstruct the subsequence using backtracking.
    vector<int> subsequence;
    if (maxLength > 0) {
        int currLen = maxLength, currIdx = N, currInc = maxIncrement;
        while (currLen > 0) {
            int prevVal = (currIdx == 0) ? 0 : dp[currIdx][currInc].second + K;
            subsequence.push_back(prevVal + currInc);
            --currLen;
            currIdx = dp[currIdx][currInc].first - 1;
            currInc = (currInc == 1) ? K : currInc - 1;
        }
    }

    // Reverse the subsequence for correct order.
    reverse(subsequence.begin(), subsequence.end());

    // Print the length and elements of the subsequence directly using cout.
    cout << maxLength << " ";
    for (int num : subsequence) {
        cout << num << " ";
    }
    cout << endl;

    //return subsequence;
}

int main() {
    int N, K;
    cin >> N >> K;

    vector<vector<int>> A(N);
    for (int i = 0; i < N; ++i) {
        int L, R, X;
        cin >> L >> R >> X;
        A[i] = {L, R, X};
    }

    longestSubsequence(N, K, A);

    return 0;
}
