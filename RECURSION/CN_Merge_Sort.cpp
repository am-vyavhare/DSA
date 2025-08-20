#include <bits/stdc++.h>
using namespace std;

void merge(vector<int>& arr, int s, int e) {
    int mid = (s + e) / 2;

    int len1 = mid - s + 1;
    int len2 = e - mid;

    // ✅ create vectors with proper sizes
    vector<int> first(len1);
    vector<int> second(len2);

    // copy values into first[]
    int mainArrayIndex = s;
    for (int i = 0; i < len1; i++) {
        first[i] = arr[mainArrayIndex++];
    }

    // copy values into second[]
    mainArrayIndex = mid + 1;
    for (int i = 0; i < len2; i++) {
        second[i] = arr[mainArrayIndex++];
    }

    // merge 2 sorted arrays
    int index1 = 0;
    int index2 = 0;
    mainArrayIndex = s;

    while (index1 < len1 && index2 < len2) {
        if (first[index1] < second[index2]) {
            arr[mainArrayIndex++] = first[index1++];
        } else {
            arr[mainArrayIndex++] = second[index2++];
        }
    }

    // copy remaining elements
    while (index1 < len1) {
        arr[mainArrayIndex++] = first[index1++];
    }

    while (index2 < len2) {
        arr[mainArrayIndex++] = second[index2++];
    }
}

void merge_Sort_solve(vector<int>& arr, int s, int e) {
    // base case
    if (s >= e) {
        return;
    }

    int mid = (s + e) / 2;

    // left sort
    merge_Sort_solve(arr, s, mid);

    // right sort
    merge_Sort_solve(arr, mid + 1, e);

    // merge
    merge(arr, s, e);
}

void mergeSort(vector<int>& arr, int n) {
    merge_Sort_solve(arr, 0, n - 1);
}

