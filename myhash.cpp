#include "myhash.h"

template <typename ValType>
MyHash<ValType>::MyHash() 
{
    for (int i = 0; i < NumBuckets; i++)
        buckets[i] = NULL;
}

template <typename ValType>
MyHash<ValType>::~MyHash() 
{
    // delete all list cells
}

template <typename ValType>
void MyHash<ValType>::add(string key, ValType val) 
{
    int whichBucket = hash(key, NumBuckets);
    cellT *match = findCell(key, buckets[whichBucket]);
    if (match != NULL)
        match->val = val;
    else {
        cellT *newOne = new cellT;
        newOne->key = key;
        newOne->val = val;
        newOne->next = buckets[whichBucket];
        buckets[whichBucket] = newOne;
    }
}

template <typename ValType>
ValType MyHash<ValType>::getValue(string key) 
{
    int whichBucket = hash(key, NumBuckets);
    cellT *match = findCell(key, buckets[whichBucket]);
    if (match != NULL)
        return match->val;
    cout << "No such key found!";
    exit(0);
}

const int Multiplier = -1664117991L;

template <typename ValType>
int MyHash<ValType>::hash(string key, int nBuckets) 
{
    unsigned long hashcode = 0;
    for (int i = 0; i < key.length(); i++)
        hashcode = hashcode * Multiplier + key[i];
    return (hashcode % nBuckets);
}

template <typename ValType>
typename MyHash<ValType>::cellT *MyHash<ValType>::findCell(string key, cellT *list) 
{
    for (cellT *cur = list; cur != NULL; cur = cur->next)
        if (cur->key == key) return cur;
    return NULL;
}