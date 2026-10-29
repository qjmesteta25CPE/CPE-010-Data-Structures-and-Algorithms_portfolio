#ifndef BUDP_H
#define BUDP_H
#include <iostream>

// Maximum value of N supported by the global DP array
const int MAX_N = 1000;

// Dynamic Programming table
int dp[MAX_N + 1];

// Helper function to return minimum of two integers
int get_min(int a, int b) {
    return (a < b) ? a : b;
}

// Precomputes minimum steps for all numbers up to max_val
void computeDP(int max_val) {
    dp[1] = 0; // Base case
    
    for (int i = 2; i <= max_val; i++) {
        // Option 1: Subtract 1
        int min_steps = 1 + dp[i - 1]; 
        
        // Option 2: Divide by 2
        if (i % 2 == 0) {
            min_steps = get_min(min_steps, 1 + dp[i / 2]);
        }
        
        // Option 3: Divide by 3
        if (i % 3 == 0) {
            min_steps = get_min(min_steps, 1 + dp[i / 3]);
        }
        
        dp[i] = min_steps;
    }
}

// Reconstructs and prints the path from N down to 1
void printPath(int n) {
    int curr = n;
        
    while (curr > 1) {
        std::cout << curr << " -> ";
        
        // Check which operation yielded the optimal value
        if (curr % 3 == 0 && dp[curr] == 1 + dp[curr / 3]) {
            curr /= 3;
        } else if (curr % 2 == 0 && dp[curr] == 1 + dp[curr / 2]) {
            curr /= 2;
        } else {
            curr -= 1;
        }
    }
    std::cout << "1\n";
}



#endif