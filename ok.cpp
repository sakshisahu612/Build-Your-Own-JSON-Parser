#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool comparePairs(const pair<int, int>& a, const pair<int, int>& b, const vector<vector<int>>& countries) {
    if (a.first == b.first) {
        return countries[a.second][1] < countries[b.second][1];
    }
    return a.first < b.first;
}

void profitDevelopment(int N, int S, int M, int ratings[], int &output1, int &output2) {    
    vector<vector<int>> countries(N / S);
    
    for (int i = 0; i < N; ++i) {
        countries[i / S].push_back(ratings[i]);
    }
    
    vector<pair<int, int>> lowestRatings;
    for (int i = 0; i < countries.size(); ++i) {
        sort(countries[i].begin(), countries[i].end());
        lowestRatings.push_back({countries[i][0], i});
    }
    
    sort(lowestRatings.begin(), lowestRatings.end(), [&](const pair<int, int>& a, const pair<int, int>& b) {
        return comparePairs(a, b, countries);
    });

    int cumulativeStates = 0;
    for (int i = 0; i < lowestRatings.size(); ++i) {
        cumulativeStates += S;
        if (M <= cumulativeStates) {
            int countryIndex = lowestRatings[i].second;
            int stateIndex = (M - 1) % S;
            output1 = countryIndex + 1;
            output2 = countries[countryIndex][stateIndex];
            return;
        }
    }

    output1 = -1;
    output2 = -1;
}

int main() {
    int N = 6;
    int S = 3;
    int M = 6;
    int ratings[] = {2, 1, 9, 3, 1, 4};

    int output1, output2;
    profitDevelopment(N, S, M, ratings, output1, output2);

    cout << "Output1: " << output1 << endl;
    cout << "Output2: " << output2 << endl;

    return 0;
}
