#ifndef BUFFER_H
#define BUFFER_H

#include <iostream>

using namespace std;

class Buffer {
  public:
    Buffer();
    ~Buffer();
    void insertCharacter(char ch);
    void deleteCharacter();
    void moveCursorToBegin();
    void moveCursorForward();
    void moveCursorToEnd();
    void moveCursorBackward();
  private:
    struct cellT {
      char val;
      cellT *next;
    };
    cellT *head;
};


#endif