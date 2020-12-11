#ifndef MYHASH_H
#define MYHASH_H

#include <string>
#include <iostream>

using namespace std;

template <typename ValType>
class MyHash {
    public:
      MyHash();
      ~MyHash();

      void add(string key, ValType val);
      ValType getValue(string key);
      
    private:
      static const int NumBuckets = 99;
      struct cellT {
          string key;
          ValType val;
          cellT *next;
      };
      cellT *buckets[NumBuckets];
      int hash(string key, int nBuckets);
      cellT *findCell(string key, cellT *list);
};

#include "myhash.cpp"

#endif