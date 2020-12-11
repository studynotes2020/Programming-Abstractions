#include <iostream>
#include <vector>

using namespace std;

// Sort template with callback fn
// Now can work for all types!
template <typename Type>
void SelectionSort(vector<Type> &v, int (cmp)(Type, Type)) {
    int n = v.size();
    for (int lh = 0; lh < n; lh++) {
        int minIndex = lh;  // find index of min from 0 to n-1
        for (int i = lh + 1; i < n; i++) {
            if (cmp(v[i], v[minIndex]) < 0) 
                minIndex = i;
        }
        swap(v[lh], v[minIndex]);  // swap min to front
    }
}

int IntCmp(int n1, int n2) {
    if (n1 > n2) return 1;
    else if (n1 < n2) return -1;
    else return 0;
}

int ReverseCmp(int n1, int n2) {
    if (n1 < n2) return 1;
    else if (n1 > n2) return -1;
    else return 0;
}

int main() {
    vector<int> v = {5, 4, 3, 2, 1, 324, 12};
    SelectionSort(v, ReverseCmp);
    for (auto &i : v) {
        cout << i << " ";
    }

    return 0;
}