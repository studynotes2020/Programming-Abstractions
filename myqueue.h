#ifndef _MYQUEUE_H
#define _MYQUEUE_H

#include <iostream>

using namespace std;

template <typename ElemType>
class MyQueue {
  public:
    MyQueue();
    ~MyQueue();

    bool isEmpty();
    void enqueue(ElemType e);
    ElemType dequeue();

  private:
    struct cellT {
      ElemType val;
      cellT *next;
    };
    cellT *head, *tail;
};


#include "myqueue.cpp"

#endif
