#include "myvector.h" 
/*
  bcs we are running: g++ Lec18.cpp -o Lec18
  if run g++ myvector.cpp Lec18.cpp -o Lec18
  we don't need to #include "myvector.h"
*/

// #include "myvector.cpp"

using namespace std;

int main() {
    MyVector<int> v;
    v.add(1);
    v.add(2);
    v.add(3);
    v.insertAt(0, 4);

    // for (int i = 0; i < v.size(); i++)
    //     cout << v.getAt(i) << endl;

    // MyVector<int> w = v;  // to demostrate change in w also affects v
    // w.setAt(0, 100);
    // for (int i = 0; i < v.size(); i++)
    //     cout << v.getAt(i) << endl;

    for (int i = 0; i < v.size(); i++)
        cout << v.getAt(i) << endl;

    return 0;
}