#include <iostream>
#include "BUDP.h"

int main() {
    // Array of test values
    int testCases[] = {1, 4, 7, 10, 28, 100};
    std::size_t numTests = sizeof(testCases) / sizeof(testCases[0]);

    // Determine highest N to precompute table in a single pass
    int maxN = testCases[0];
    for (std::size_t i = 1; i < numTests; i++) {
        if (testCases[i] > maxN) {
            maxN = testCases[i];
        }
    }

    // Precompute up to maxN
    computeDP(maxN);

    // Print table header
    std::cout << "  BOTTOM-UP DP RESULTS \n";

    // Output each test case
    for (std::size_t i = 0; i < numTests; i++) {
        int n = testCases[i];
        std::cout << "N = " << n << " | Min Steps: " << dp[n] << " | Path: ";
        printPath(n);
    }


    return 0;
}