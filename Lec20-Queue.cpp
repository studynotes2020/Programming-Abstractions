#include "myqueue.h"

int main() {
    MyQueue<int> q;
    q.enqueue(1);
    q.enqueue(2);
    cout << q.dequeue() << endl;
    cout << q.dequeue() << endl;
    cout << q.dequeue() << endl;

    return 0;
}