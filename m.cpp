#include<bits/stdc++.h>
using namespace std;

long rearrangeStudents(vector<int> arrA, vector<int> arrB) {
    int n = arrA.size();

    // Sort both arrays in descending order
    sort(arrA.rbegin(), arrA.rend());
    sort(arrB.rbegin(), arrB.rend());

    long cost = 0;

    // Iterate through both arrays and calculate the cost of swaps
    for (int i = 0; i < n; i++) {
        if (arrA[i] != arrB[i]) {
            // If heights are not equal, find the minimum height and add it to the cost
            cost += min(arrA[i], arrB[i]);
        }
    }

    // If the total cost is zero, it means no swaps were needed
    if (cost == 0) {
        return 0;
    }

    // Check if the final arrays are identical
    for (int i = 0; i < n; i++) {
        if (arrA[i] != arrB[i]) {
            return -1; // Not feasible
        }
    }

    return cost;
}
int main() {
    // Sample input
    vector<int> arrA = {3,1,1,3};
    vector<int> arrB = {3,2,2,3};

    long result = rearrangeStudents(arrA, arrB);

    cout << "Minimum cost: " << result << endl;

    return 0;
}