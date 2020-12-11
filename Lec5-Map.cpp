#include <iostream>
#include <fstream>
#include <map>

using namespace std;

void ReadFile(ifstream &in, map<string, int> &m) {
    while (true) {
        string word;
        in >> word;
        if (in.fail()) break;
        if (m.count(word)) {
            m[word] += 1;
        } else {
            m[word] = 1;
        }
    }
    cout << "num unique words " << m.size() << endl;

    // Iterate using STL iterator
    map<string, int>::iterator itr = m.begin();
    while (itr != m.end()) {
        cout << itr->first << " " << itr->second << endl;
        itr++;
    }

    string max;
    int maxCount = 0;
    // Iterate using range based for loop
    for (auto i : m) {
        if (i.second > maxCount) {
            max = i.first;
            maxCount = i.second;
        }
    }
    cout << max << " " << maxCount << endl;
}

int main() {
    map<string, int> counts;
    ifstream in("zoox.txt");
    ReadFile(in, counts);
}
