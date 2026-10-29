#include <iostream>
#include <algorithm>
#include <vector>

// Use vector for dynamic sizing per test case
std::vector<int> memo;

int getMinSteps(int n) {
    if (n == 1) return 0; // base case
    if (memo[n] != -1) return memo[n]; // return cached result
    
    int r = 1 + getMinSteps(n - 1); // '-1' step
    
    // '/2' step
    if (n % 2 == 0) r = std::min(r, 1 + getMinSteps(n / 2)); 
    
    // '/3' step
    if (n % 3 == 0) r = std::min(r, 1 + getMinSteps(n / 3)); 
    
    memo[n] = r; // cache and return
    return r;
}

int main() {
    int tests[] = {1, 4, 7, 10, 25, 100};
    
    for (int n : tests) {
        // Resize and initialize the vector with -1 for the current n
        memo.assign(n + 1, -1);
        std::cout << "n=" << n << " -> minimum steps: " << getMinSteps(n) << std::endl;
    }
    
    return 0;
}