#include <iostream>
#include <vector>

using namespace std;

/*
  Function: Selection Sort

  With you left hand (lh), point at each element in the vector
  in turn, starting at index 0. At each step in the cycle:
  1. Find the smallest element in the range between your left and
     the end of the vector, and point at that element with you
     right hand (rh)
  2. Move that element into its correct position by exchanging the elements
     indicated by your left and right hands.

*/

void SelectionSort(vector<int> &v) {
    int n = v.size();
    for (int lh = 0; lh < n; lh++) {
        int minIndex = lh;  // find index of min from 0 to n-1
        for (int i = lh + 1; i < n; i++) {
            if (v[i] < v[minIndex]) minIndex = i;
        }
        // int tmp = v[lh];  
        // v[lh] = v[rh];
        // v[rh] = tmp;
        swap(v[lh], v[minIndex]);  // swap min to front
    }
}

int main() {
    vector<int> v = {5, 4, 3, 2, 1, 324, 12};
    SelectionSort(v);
    for (auto &i : v) {
        cout << i << " ";
    }

    return 0;
}