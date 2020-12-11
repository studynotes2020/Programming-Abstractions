/*

C++ string

Models a sequence of characters
string defines a class, strings are objects
  many operations are member functions that operate on receiver string
Simple operations
  member function .length returns number of chars
  sqaure brackets to access individual chars
  C++ strings are mutable! (unlike java)


C++ string vs C-string

C++ inherits legacy of old-style C-string
  pointer to character array, null terminated
  string literals are actually C-strings
Converting C-string to C++ string
  Happens automatically in most contexts
  Can force using string("abc")
Converting C++ string to C-string
  Using member function a.c_str()
Why do you care?
  Some older functionality requires use of C-string
  C-string not quite compatible with concatenation


Concatenation pitfall

If one operand is true C++ string, all good
  string str = "abc";
  str + "def";
  str + 'd';
  str + ch;
If both operands are C-string/char, bad times
  "abc" + "def"  // won't compile
  "abc" + 'd'  // compiles, but doesn't work
  "abc" + ch  // same
Can force conversion if needed
  string("abc") + ch

*/

#include <iostream>       // std::cout
#include <string>         // std::string

using namespace std;

int main() {
    string s;
    s = "cs106";
    for (int i = 0; i < s.length(); i++) {
        s[i] = toupper(s[i]);
    }
    cout << s << endl;

    string t = "hello";
    s = t;  // copy t to s
    t[0] = 'j';  // single quote for char
    s = s + ' ';  // + overloaded to do concatenation
    if (s != t) t += t;
    cout << t << endl;

    return 0;
}