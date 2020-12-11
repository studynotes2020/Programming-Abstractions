#include <iostream>

using namespace std;

int CountOccurrences(char ch, string s) 
{
    int count = 0;
    for (int i = 0; i < s.length(); i++) 
        if (s[i] == ch) count++;
    
    return count;
}

string RemoveOccurrences(char ch, string s) 
{
    string result = "";
    for (int i = 0; i < s.length(); i++) 
        if (s[i] != ch) result += s[i];
    
    return result;
}

void RemoveOccurrences2(char ch, string &s) 
{
    int found = 0;
    // npos: Maximum value for size_t 
    while ((found = s.find(ch, found)) != string::npos) // find will start from found index in next loop
        s.erase(found, 1); 
}

int main()
{
    string s = "chihuahuas cheese crackers";
    cout << CountOccurrences('c', s) << endl;

    RemoveOccurrences2('c', s);
    cout << s << endl;

    return 0;
}