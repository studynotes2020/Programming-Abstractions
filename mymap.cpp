#include "mymap.h"

template <typename ValType>
MyMap<ValType>::MyMap() {

}

template <typename ValType>
MyMap<ValType>::~MyMap() {

}

template <typename ValType>
void MyMap<ValType>::add(string key, ValType val) {
    pairT p;
    int found = findIndexForKey(key);
    if (found != -1) {
        entries[found].val = val;
    } else {
        p.key = key;
        p.val = val;
        entries.push_back(p);
    }
}

template <typename ValType>
ValType MyMap<ValType>::getValue(string key) {
    pairT p;
    int found = findIndexForKey(key);
    if (found != -1) return entries[found].val;
    cout << "key not found!";
    exit(0);
}

template <typename ValType>
int MyMap<ValType>::findIndexForKey(string key) {
    pairT p;
    for (int i = 0; i < entries.size(); i++)
        if (entries[i].key == key) return i;

    return -1;
}
