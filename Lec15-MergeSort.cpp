#include <iostream>
#include <vector>

using namespace std;

vector<int> Copy(vector<int> &v, int start, int end) {
    vector<int> res(end - start);
    int j = 0;
    for (int i = start; i < end; i++) {
        res[j] = v[i];
        j++;
    }

    return res;
}

void Merge(vector<int> &A, vector<int> &arr1, vector<int> &arr2) {
    int p, p1, p2;
    p = p1 = p2 = 0;
    while (p1 < arr1.size() && p2 < arr2.size()) {
        if (arr1[p1] < arr2[p2])
            A[p++] = arr1[p1++];
        else
            A[p++] = arr2[p2++];
    }
    while (p1 < arr1.size()) A[p++] = arr1[p1++];
    while (p2 < arr2.size()) A[p++] = arr2[p2++];
}

void MergeSort(vector<int> &v) {
    if (v.size() > 1) {
        int n1 = v.size()/2;
        int n2 = v.size();
        vector<int> left = Copy(v, 0, n1); // O(n/2)
        vector<int> right = Copy(v, n1, n2);  // O(n/2)
        MergeSort(left);
        MergeSort(right);
        Merge(v, left, right);  // O(n)
    }
}

int main() {
    vector<int> v = {5, 4, 3, 2, 1, 324, 12};
    MergeSort(v);
    for (auto &i : v) {
        cout << i << " ";
    }

    return 0;
}