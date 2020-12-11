#include "myvector.h"

template <typename ElemType>
MyVector<ElemType>::MyVector() {
    arr = new ElemType[10];
    numAllocated = 10;
    numUsed = 0;
}

template <typename ElemType>
MyVector<ElemType>::~MyVector() {
    delete[] arr;
}

template <typename ElemType>
int MyVector<ElemType>::size() {
    return numUsed;
}

template <typename ElemType>
void MyVector<ElemType>::add(ElemType s) {
    if (numUsed == numAllocated) {
        doubleCapacity();
    }
    arr[numUsed++] = s;
}

template <typename ElemType>
ElemType MyVector<ElemType>::getAt(int index) {
    if (index < 0 || index >= size()) {
      cout << "Error: Out of bounds";
      exit(0);
    }
    return arr[index];
}

template <typename ElemType>
void MyVector<ElemType>::setAt(int index, ElemType v) {
    if (index < 0 || index >= size()) {
      cout << "Error: Out of bounds";
      exit(0);
    }
    arr[index] = v;
}

template <typename ElemType>
void MyVector<ElemType>::insertAt(int index, ElemType v) {
    if (index < 0 || index >= size()) {
      cout << "Error: Out of bounds";
      exit(0);
    }
    if (numUsed == numAllocated) {
        doubleCapacity();
    }
    for (int i = size()-1; i >= index; i--) {
        arr[i + 1] = arr[i];
    }
    arr[index] = v;
    numUsed++;
}

template <typename ElemType>
void MyVector<ElemType>::removeAt(int index) {
    if (index < 0 || index >= size()) {
      cout << "Error: Out of bounds";
      exit(0);
    }
    for (int i = size()-1; i >= index; i--) {
        arr[i + 1] = arr[i];
    }
    numAllocated--;
    numUsed--;
}

template <typename ElemType>
void MyVector<ElemType>::doubleCapacity() {
    ElemType *bigger = new ElemType[numAllocated*2];
    for (int i = 0; i < numUsed; i++)
        bigger[i] = arr[i];
    delete[] arr;
    arr = bigger;
    numAllocated *= 2;
}
