#include "buffer.h"

Buffer::Buffer() 
{

}

Buffer::~Buffer()
{
    // delete buffer
}

void Buffer::insertCharacter(char ch) {
    cellT *cp = new cellT;
    cp->ch = ch;
    cp->next = cursor->next;
    cursor->next = cp;
    cursor = cp;  // cursor stay before ch so next ch can be add easily
}

void Buffer::deleteCharacter() {
    if (cursor->next != NULL) {
        cellT *old = cursor->next;
        cursor->next = old->next;
        delete old;
    }
}

void Buffer::moveCursorToBegin() {
    cursor = head;
}

void Buffer::moveCursorForward() {
    if (cursor->next != NULL)
        cursor = cursor->next;
}

void Buffer::moveCursorToEnd() {
    while (cursor->next != NULL)
        moveCursorForward();
}

void Buffer::moveCursorBackward() {
    if (cursor != head) {
        cellT *cp = head;
        while (cp->next != cursor)
            cp = cp->next;
        cursor = cp;
    }
}