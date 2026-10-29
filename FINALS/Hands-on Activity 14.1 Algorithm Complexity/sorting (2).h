#ifndef SORTING_H
#define SORTING_H


#include <utility> // for std::swap


// Merge two sorted halves using one temporary array.
void mergeSort(int a[], int temp[], int left, int right) {
    if (left >= right) return;
   
    int mid = left + (right - left) / 2; // Prevents overflow
    mergeSort(a, temp, left, mid);
    mergeSort(a, temp, mid + 1, right);
   
    int i = left, j = mid + 1, k = left;
    while (i <= mid && j <= right) {
        if (a[i] <= a[j]) temp[k++] = a[i++];
        else temp[k++] = a[j++];
    }
   
    while (i <= mid) temp[k++] = a[i++];
    while (j <= right) temp[k++] = a[j++];
   
    for (i = left; i <= right; i++) a[i] = temp[i];
}


// The last value is the quicksort pivot.
void quickSort(int a[], int low, int high) {
    if (low >= high) return;
   
    int pivot = a[high];
    int i = low;
    for (int j = low; j < high; j++) {
        if (a[j] < pivot) {
            std::swap(a[i], a[j]);
            i++;
        }
    }
    std::swap(a[i], a[high]);
   
    quickSort(a, low, i - 1);
    quickSort(a, i + 1, high);
}


// Start with ascending values. Prepare balanced pivot positions.
void makeQuickBest(int a[], int low, int high) {
    if (low >= high) return;
    int mid = low + (high - low) / 2;
    makeQuickBest(a, low, mid - 1);
    makeQuickBest(a, mid + 1, high);
    std::swap(a[mid], a[high]);
}


// Start with ascending values. Interleave values at each merge.
void makeMergeWorst(int a[], int n) {
    if (n <= 1) return;
    int temp[10000];
    int leftSize = (n + 1) / 2;
    int i = 0, j = leftSize;
   
    for (int k = 0; k < n; k++) {
        if (k % 2 == 0) temp[i++] = a[k];
        else temp[j++] = a[k];
    }
   
    for (int k = 0; k < n; k++) a[k] = temp[k];
   
    makeMergeWorst(a, leftSize);
    makeMergeWorst(a + leftSize, n - leftSize);
}


bool isSorted(int a[], int n) {
    for (int i = 1; i < n; i++) {
        if (a[i - 1] > a[i]) return false;
    }
    return true;
}


#endif
