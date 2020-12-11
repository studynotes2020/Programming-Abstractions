
#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <set>

using namespace std;

void swap(char &ch1, char &ch2) {
    char tmp = ch1;
    ch1 = ch2;
    ch2 = tmp;
}

string Signature(string s) {
    for (int i = 0; i < s.length(); i++) {
        int minIndex = i;
        for (int j = i + 1; j < s.length(); j++)
            if (s[j] < s[minIndex])
                minIndex = j;
        swap(s[i], s[minIndex]);
    }
    return s;
}

void ReadFile(ifstream &in, map<string, set<string>> &m) {
    while (true) {
        string word;
        in >> word;
        if (in.fail()) break;
        m[Signature(word)].insert(word);
    }
    cout << "num words " << m.size() << endl;

    map<string, set<string>>::iterator itr = m.begin();
    int maxSize = 0;
    string maxKey;
    while (itr != m.end()) {
        // cout << itr->first << " " << itr->second.size() << endl;
        if (itr->second.size() > maxSize) {
            maxKey = itr->first;
            maxSize = itr->second.size();
        }
        itr++;
    }
    cout << "max is " << maxKey << endl;
    set<string>::iterator it = m[maxKey].begin();
    while (it != m[maxKey].end()) {
        cout << *it << " ";
        it++;
    }

}

int main() {
    ifstream in("zoox.txt");
    map<string, set<string>> m;
    ReadFile(in, m);
    return 0;
}