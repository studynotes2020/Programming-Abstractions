#ifndef _MyStack_H
#define _MyStack_H

#include "myvector.h"

template <typename ElemType>
class MyStack {
  public:
    MyStack();
    ~MyStack();

    int size(); // if implement stack using vector
    bool isEmpty();
    void push(ElemType e);
    ElemType pop();

  private:
    // MyVector<ElemType> elems;  // if implement stack uwing vector
    struct cellT {
      ElemType val;
      cellT *next;
    };
    cellT *head;
};


#include "mystack.cpp"

#endif
