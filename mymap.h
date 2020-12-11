#ifndef MYMAP_H
#define MYMAP_H

#include <vector>
#include <string>

using namespace std;

template <typename ValType>
class MyMap {
    public:
      MyMap();
      ~MyMap();

      void add(string key, ValType val);
      ValType getValue(string key);
      

    private:
      struct pairT {
          string key;
          ValType val;
      };
      vector<pairT> entries;
      int findIndexForKey(string key);
};

#include "mymap.cpp"

#endif