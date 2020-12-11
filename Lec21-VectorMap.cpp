#include <iostream>
#include "mymap.h"

int main() {
    MyMap<int> m;
    m.add("car", 3);
    cout << m.getValue("car") << endl;
    m.add("car", 432);
    cout << m.getValue("car") << endl;

    return 0;
}