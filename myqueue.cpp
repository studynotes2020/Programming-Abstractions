#include "myqueue.h"

template <typename ElemType>
MyQueue<ElemType>::MyQueue() {
    head = tail = NULL;
}

template <typename ElemType>
MyQueue<ElemType>::~MyQueue() {
    // delete all cells
}

template <typename ElemType>
bool MyQueue<ElemType>::isEmpty() {
    return (head == NULL);
}

template <typename ElemType>
ElemType MyQueue<ElemType>::dequeue() {
    if (isEmpty()) {
        cout << "dequeue empty queue";
        exit(0);
    }
    ElemType front = head->val;
    cellT *old = head;
    head = head->next;
    delete old;
    return front;
}

template <typename ElemType>
void MyQueue<ElemType>::enqueue(ElemType s) {
    cellT *newCell = new cellT;
    newCell->val = s;
    newCell->next = NULL;
    if (isEmpty()) {
        head = tail = newCell;
    } else {
        tail->next = newCell;
        tail = newCell;
    }
}