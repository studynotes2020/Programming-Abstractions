#ifndef _MyVector_H
#define _MyVector_H

#include <string>
#include <iostream>

using namespace std;

template <typename ElemType>
class MyVector {
  public:
    MyVector();
    ~MyVector();

    int size();
    void add(ElemType s);
    ElemType getAt(int index);
    void setAt(int index, ElemType v);
    void insertAt(int index, ElemType v);
    void removeAt(int index);
    
  private:
    ElemType *arr;
    int numUsed, numAllocated;
    void doubleCapacity();

    // A macro not implemented. Disallow shallow copy, Makeing operator= private
    DISALLOW_COPYING(MyVector); 

};

#include "myvector.cpp"  // dump all the cpp code here
/*
  Quirky C++ template compilation
  - class.cpp is not added to the project (not compiled normally)
  - class.h has #include "class.cpp" at end to pull in code
  - Including a .cpp file is wacky only used for class template situation

*/

#endif