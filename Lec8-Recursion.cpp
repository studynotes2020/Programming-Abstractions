#include <iostream>

using namespace std;

int Raise(int base, int exp) {
    if (exp == 0)
        return 1;
    else
        return base * Raise(base, exp-1);
}

int Raise2(int base, int exp) {
    if (exp == 0)
        return 1;
    else {
        int half = Raise2(base, exp/2);  // faster to reach base case, more efficient
        if (exp % 2 == 0)
            return half * half;
        else
            return base * half * half;
    }
}

/*
  Aim for simple, clean base case (Not Raise3)
  1. No need to anticipate other earlier stepping points
  2. Avoid looking ahead before recursive calls, just let simple base case handle
*/
int Raise3(int base, int exp) {
    if (exp == 0) return 1;
    else if (exp == 1) return base;
    else if (exp == 2) return base * base;
    else if (exp == 3) return base * base * base;
    else return base * Raise3(base, exp-1);
}

int main() {
    cout << Raise2(2, 30) << endl;
    return 0;
}
