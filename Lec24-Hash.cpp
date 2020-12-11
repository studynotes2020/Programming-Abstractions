#include "myhash.h"

/*

Hash function maps key to a number
  Result constrained to some range
  Result is stable
    Same key in, same number out

Goal to distribute key over range
  Bad if many keys map to 17 and none to 22

Possible hash functions
  First letter?
  Length of word?
  Sum of ASCII values for letters?

Hash Collisions
1. What happen if several keys hash to same code?
     Called a collision
2. Good hash function tries to avoid, but no guarantee
3. One strategy is "chaining"
     Keys within bucket are stored in a linked list
     Each list expected to be small, so easy to traverse

Compare Map implementations
          Vector  Sorted Vector  BST     Hash
getValue  O(N)    O(lgN)         O(lgN)  O(1)
add       O(N)    O(N)           O(lgN)  O(1)

*/

int main() {
    MyHash<int> h;
    h.add("car", 3);
    h.add("car", 4);
    h.add("cat", 5);
    cout << h.getValue("car") << endl;
    cout << h.getValue("cat") << endl;
    cout << h.getValue("dog") << endl;
    return 0;
}