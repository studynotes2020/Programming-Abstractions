#include "mystack.h"

template <typename ElemType>
MyStack<ElemType>::MyStack() {
    head = NULL;
}

template <typename ElemType>
MyStack<ElemType>::~MyStack() {
    // delete the entire list
}

template <typename ElemType>
bool MyStack<ElemType>::isEmpty() {
    return (head == NULL);
}

template <typename ElemType>
ElemType MyStack<ElemType>::pop() {
    if (isEmpty()) {
        cout << "pop empty stack";
        exit(0);
    }
    ElemType top = head->val;
    cellT *old = head;
    head = head->next;
    delete old;
    return top;
}

template <typename ElemType>
void MyStack<ElemType>::push(ElemType s) {
    cellT *newCell = new cellT;
    newCell->val = s;
    newCell->next = head;
    head = newCell;
}