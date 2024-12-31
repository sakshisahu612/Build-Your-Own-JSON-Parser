#include <iostream>
#include <vector>
#include <string>

using namespace std;

int max_length = 0;

void dfs(const vector<string>& A, int N, vector<bool>& visited, int current, int length) {
    visited[current] = true;
    max_length = (length > max_length) ? length : max_length;

    for (int i = 0; i < N; i++) {
        if (!visited[i] && A[current][1] == A[i][0]) {
            dfs(A, N, visited, i, length + 1);
        }
    }

    visited[current] = false;
}

int solution(const vector<string>& A) {
    int N = A.size();
    vector<bool> visited(N, false);
    max_length = 0;

    for (int i = 0; i < N; i++) {
        dfs(A, N, visited, i, 1);
    }

    return max_length;
}

int main() {
    // Test case 1: Basic Test Case
    vector<string> test1 = {"RR", "GR", "RG", "GR", "GR", "RR"};
    cout << "Test Case 1 - Longest sequence length: " << solution(test1) << endl;

    // Test case 2: No Matching Pairs
    vector<string> test2 = {"GG", "GG", "RR", "GG", "RR"};
    cout << "Test Case 2 - Longest sequence length: " << solution(test2) << endl;

    // Test case 3: All Pairs Match
    vector<string> test3 = { "RG", "GR", "RG", "GR" };
    cout << "Test Case 3 - Longest sequence length: " << solution(test3) << endl;

    // Test case 4: Single Pair
    vector<string> test4 = {"RG"};
    cout << "Test Case 4 - Longest sequence length: " << solution(test4) << endl;

    // Test case 5: Large Case
    vector<string> test5 = {"GR", "RG", "GR", "RG", "GR", "RG", "GR", "RG", "GR", "RG"};
    cout << "Test Case 5 - Longest sequence length: " << solution(test5) << endl;

    return 0;
}
