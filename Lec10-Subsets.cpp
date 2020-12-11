#include <iostream>

using namespace std;

/*
  Subsets
  - Separate one element from input
  - Can either include in current subset or not
  - Recursively form subsets including it
  - Recursively form subsets not including it
  - What is the base case?

  Subset strategy
  - Result is empty, starting input is "abcd"
  - Consider first element "a"
  - Add to subset, remaining input is "bcd"
  - Recursively find all subsets from here
  - Repeat recursion without including "a"

  Subsets("", "abcd")
    /            \
  ("a","bcd")   ("", bcd")
      /      \____________________
("ab", "cd")                 ("a","cd")
     /      \                   /      \
("abc", "d") ("ab","d")     ("ac","d")  ("a","d")
    /\            /\           /\          /\
abcd, abc      abd, ab      acd  ac       ad  a

*/

void RecSubsets(string soFar, string rest) {
    if (rest == "")
        cout << soFar << endl;
    else {
        // add to subset, remove from rest, recur
        RecSubsets(soFar + rest[0], rest.substr(1));
        //don't add to subset, remove from rest, recur
        RecSubsets(soFar, rest.substr(1));
    }
}

void ListSubsets(string str) {
    RecSubsets("", str);
}

int main() {
    string s = "abcd";
    ListSubsets(s);

    return 0;
}