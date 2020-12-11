#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

bool IsPalindrome(string s) {
    if (s.length() <= 1) return true;
    return s[0] == s[s.length()-1] && IsPalindrome(s.substr(1, s.length()-2));
}

string removeSpaces(string str)  
{ 
    // string::iterator itr = remove(str.begin(), str.end(), ' ');
    // spaces removed but string length preserved, so need erase
    str.erase(remove(str.begin(), str.end(), ' '), str.end()); 
    return str; 
} 

int main() {
    // string s = "was it a car or a cat i saw";
    string s = "go hang a salami im a lasagna hog";
    s = removeSpaces(s);
    cout << s << "\n" << IsPalindrome(s) << endl;
    return 0;
}