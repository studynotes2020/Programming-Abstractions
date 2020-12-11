#include <iostream>
#include <vector>
#include <string>

using namespace std;

const int NotFound = -1;

int BSearch(vector<int> &v, int start, int stop, int key) {
    if (start > stop) return NotFound;

    int mid = (start + stop) / 2;
    if (key == v[mid])
        return mid;
    else if (key < v[mid])
        return BSearch(v, start, mid-1, key);
    else
        return BSearch(v, mid+1, stop, key);
}

int main() {
    vector<int> A = {1, 3, 4, 34, 56, 123};
    cout << BSearch(A, 0, A.size()-1, 56);  // return index

    return 0;
}