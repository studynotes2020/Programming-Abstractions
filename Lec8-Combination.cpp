#include <iostream>

using namespace std;

int C(int n, int k) {
    if (k == 0 || k == n)
        return 1;
    else {
        // Num of subsets that includes picked
        // plus Num of subsets that don't include picked
        return C(n-1, k) + C(n-1, k-1);
    }
}

int main() {
    /*
      Given N things, how many different ways can you choose K of them?
      N-choose-k, written as C(n, k)
    */
    cout << C(4, 2) << endl;

    return 0;
}