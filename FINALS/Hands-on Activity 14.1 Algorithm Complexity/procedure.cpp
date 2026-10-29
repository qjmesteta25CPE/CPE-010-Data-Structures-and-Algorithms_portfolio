#include <iostream>
#include <iomanip>
#include <random>
#include <chrono>
#include <string>
#include "sorting.h"


using namespace std;


// Helper to measure time cleanly
template<typename Func>
double measureTime(Func f) {
    auto start = chrono::steady_clock::now();
    f();
    auto end = chrono::steady_clock::now();
    return chrono::duration<double, milli>(end - start).count();
}


int main() {
    const int sizes[] = {100, 1000, 10000};
    int mergeData[10000], quickData[10000], temp[10000];
   
    // Modern C++ Random Number Generation
    mt19937 rng(14);
    uniform_int_distribution<int> dist(0, 100000);


    cout << fixed << setprecision(4);
    cout << left << setw(8) << "N"
         << setw(10) << "Case"
         << setw(15) << "Merge_ms"
         << setw(15) << "Quick_ms"
         << "Sorted?\n";
    cout << string(55, '-') << "\n";


    for (int n : sizes) {
        for (int test = 0; test < 3; test++) {
            string label;
           
            // 1. Generate Data based on the Case
            for (int i = 0; i < n; i++) {
                if (test == 0) { // Best Case
                    label = "Best";
                    mergeData[i] = i; // Merge's best case is already sorted
                    quickData[i] = i;
                } else if (test == 1) { // Worst Case
                    label = "Worst";
                    mergeData[i] = i;
                    quickData[i] = i; // Ascending is QuickSort's worst case (last-elem pivot)
                } else { // Random Case
                    label = "Random";
                    int val = dist(rng);
                    mergeData[i] = val;
                    quickData[i] = val;
                }
            }


            // Apply special permutations for specific algorithm cases
            if (test == 0) makeQuickBest(quickData, 0, n - 1);
            if (test == 1) makeMergeWorst(mergeData, n);


            // 2. Measure Merge Sort (Sequential)
            double mergeTime = measureTime([&]() {
                mergeSort(mergeData, temp, 0, n - 1);
            });


            // 3. Measure Quick Sort (Sequential)
            double quickTime = measureTime([&]() {
                quickSort(quickData, 0, n - 1);
            });


            bool correct = isSorted(mergeData, n) && isSorted(quickData, n);


            // 4. Output Results cleanly
            cout << left << setw(8) << n
                 << setw(10) << label
                 << setw(15) << mergeTime
                 << setw(15) << quickTime
                 << (correct ? "Yes" : "NO!") << '\n';
        }
        cout << string(55, '-') << "\n";
    }
    return 0;
}
