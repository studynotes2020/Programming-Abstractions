#include "treemap.h"

int main() {
    TreeMap<int> m;
    m.add("car", 3);
    m.add("dog", 5);
    cout << m.getValue("car") << endl;
    cout << m.getValue("dog") << endl;

    return 0;
}