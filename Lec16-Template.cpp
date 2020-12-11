#include <iostream>

using namespace std;

/*
Template instantiated with Type => int
Compiler internally names this version Swap<int>
Code is the compiled
*/
template <typename Type>
void Swap(Type &a, Type &b) {
    Type tmp = a;
    a = b;
    b = tmp;
}

// Works on primitive type but not for non-primitive type
template <typename T>
void PrintVector(vector<T> &v) {
    for (int i = 0; i < v.size(); i++)
        cout << v[i] << " ";
    cout << endl;
}

int main() {
    int one = 54, two = 32;
    Swap(one, two);
    cout << one << " " << two << endl;
    string s = "hello", t = "world";
    Swap(s, t);
    cout << s << " " << t << endl;
    return 0;
}