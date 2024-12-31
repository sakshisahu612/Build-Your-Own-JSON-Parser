#include<bits/stdc++.h>
#include<string>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

using namespace std;

int solution(string &S, string &T) {
    // Implement your solution here
    int n = S.length();
    vector<int> different_indices;
    for(int i = 0; i<n; i++){
        if(S[i] != T[i]){
            different_indices.push_back(i);
        }
    }
    int swaps = 0;
    for(int i = 0; i<different_indices.size(); i++){
        int index = different_indices[i];
        int mini = abs(S[index]-T[index]);
        int swap_index = -1;

        for(int j = i+1; j<different_indices.size(); j++){
            int other_index = different_indices[j];
            int new_difference = abs(S[other_index]-T[index] + abs(S[index] - T[other_index]));
            if(new_difference < mini){
                mini = new_difference;
                swap_index = j;
            }
        }

        if(swap_index != -1){
            swap(S[different_indices[i]], S[different_indices[swap_index]]);
            swaps++;
            different_indices.erase(different_indices.begin() + swap_index);
        }
    }
    return swaps;
}

int main(){
    string S, T;
    cin >> S >> T;
    int ans = solution(S, T);
    cout << ans << endl;
}
