#include <iostream>
#include <fstream>
#include <set>
#include <cstdlib>
#include <random>

using namespace std;

void TestRandom() {
    set<int> seen;
    while (true) {
        int num = rand() % 101;
        if (seen.count(num)) break;
        seen.insert(num);
    }
    cout << "found " << seen.size() << " before repeat" << endl;

    for (set<int>::iterator it=seen.begin(); it!=seen.end(); ++it) {
        cout << *it << endl;
    }
}

int main() {
    TestRandom();

    return 0;
}