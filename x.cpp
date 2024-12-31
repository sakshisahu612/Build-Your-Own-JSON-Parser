#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> getRequiredSweeps(vector<int>& ping) {
    int n = ping.size(); // Number of signals
    vector<int> signal(n, 0); // Initialize all signals to 0
    vector<int> sweeps(n); // Stores the number of sweeps after each ping

    for (int i = 0; i < n; ++i) {
        int pingIndex = ping[i] - 1; // Adjust for 0-based indexing

        // Update signal based on the ping
        signal[pingIndex] = 1;

        int swaps = 0;
        bool isSorted = false;

        // Perform sweeps until the array is sorted
        while (!isSorted) {
            isSorted = true; // Assume sorted initially

            for (int j = 0; j < n - 1; ++j) {
                if (signal[j] == 1 && signal[j + 1] == 0) {
                    swap(signal[j], signal[j + 1]);
                    isSorted = false; // Not sorted yet if a swap occurred
                    swaps++;
                }
            }
        }

        sweeps[i] = swaps; // Store the number of sweeps for this ping
    }

    return sweeps;
}
int main() {
    vector<int> ping = {1, 2, 4, 3}; // Example input
    vector<int> result = getRequiredSweeps(ping);

    for (int sweeps : result) {
        cout << sweeps << " ";
    }

    return 0;
}
