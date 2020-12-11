#include <iostream>
#include <vector>

using namespace std;

int Partition(vector<int> &A, int start, int stop) {
    int lh = start + 1, rh = stop, pivot;
    pivot = A[start];
    while (true) {
        while (lh < rh && A[rh] >= pivot) rh--;
        while (lh < rh && A[lh] < pivot) lh++;
        if (lh == rh) break;
        swap(A[lh], A[rh]);
        // invariant: A[start+1...lh] < pivot && A[rh...stop] >= pivot
    }
    if (A[lh] >= pivot) return start;
    swap(A[start], A[lh]);
    return lh;
}

void QuickSort(vector<int> &A, int start, int stop) {
    if (stop > start) {
        int pivot = Partition(A, start, stop);  // O(N)
        QuickSort(A, start, pivot-1); // Assume ideal 50/50 split
        QuickSort(A, pivot+1, stop);  // logN
        // Assume worst N-1/1 split, revese sorted or sorted array -> O(N^2)
        // Choose pivot differently: Actual median, approximate median, random
    }
}

int main() {
    vector<int> v = {5, 4, 3, 2, 1, 324, 12};
    QuickSort(v, 0, v.size()-1);
    for (auto &i : v) {
        cout << i << " ";
    }

    return 0;
}