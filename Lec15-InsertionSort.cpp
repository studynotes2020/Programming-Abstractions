#include <iostream>
#include <vector>

using namespace std;

void InsertionSort(vector<int> &v) {
    for (int i = 1; i < v.size(); i++) {
        int j, cur = v[i];
        for (j = i - 1; j >= 0 && v[j] > cur; j--) {
            v[j + 1] = v[j];
        }
        v[j + 1] = cur;
    }
}

int main() {
    vector<int> v = {5, 4, 3, 2, 1, 324, 12};
    InsertionSort(v);
    for (auto &i : v) {
        cout << i << " ";
    }

    return 0;
}