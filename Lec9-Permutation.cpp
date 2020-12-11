#include <iostream>

using namespace std;

/*
1. Want to enumerate all rearrangements:
    - ABCD permutes to DCBA, CABD etc
2. Solving recursively 
    - Choose a letter from input to appedn to output
    - Recursively permute remaining letters onto output
    - What other options do you need to explore
    - How to ensure each letter is used exactly once?
    - What is the base case?

"ABC" -> ("A","BC"), ("B","AC"), ("C","AB")
("A","BC") -> ("AB", "C"), ("AC", "B")
("AB", "C") -> ("ABC", "")

If ABCD
Permute("","ABCD")
-> P("A", "BCD"), P("B", "ACD"), P("C", "ABD"), P("D", "ABC")
    |           \_______________________________________
    |                                |                  \
-> P("AB","CD"),               P("AC","BD"),       P("AD","BC")
    /           \                   /      \ 
-> P("ABC","D"), P("ABD","C"), P("ACB","D"), P("ACD","B")
    /             \              /             \
-> P("ABCD",""), P("ABDC",""), P("ACBD",""), P("ACDB","")
*/

void RecPermute(string soFar, string rest) {
    if (rest == "") {
        cout << soFar << endl;
    } else {
        for (int i = 0; i < rest.length(); i ++ ){
            string next = soFar + rest[i];
            string remaining = rest.substr(0, i) + rest.substr(i+1);
            RecPermute(next, remaining);
        }
    }
}

// "wrapper function"
void ListPermutations(string s) {
    RecPermute("", s);
}

int main() {
    string s = "ABCD";
    ListPermutations(s);

    return 0;
}