#include <iostream>
#include <vector>

std::vector<long> getProcessTime(const std::vector<int>& time) {
    std::vector<long> coreTime(2, 0);

    // Assign each process to the core with the smaller current total time
    for (int t : time) {
        if (coreTime[0] <= coreTime[1]) {
            coreTime[0] += t;
        } else {
            coreTime[1] += t;
        }
    }

    return coreTime;
}

int main() {
    // Example test case
    std::vector<int> time = {5,3};

    std::vector<long> result = getProcessTime(time);

    std::cout << "Total time for core 1: " << result[0] << std::endl;
    std::cout << "Total time for core 2: " << result[1] << std::endl;

    return 0;
}
