#include <iostream>
#include <fstream>

using namespace std;

int CountLine(ifstream &in) {
    int count = 0;
    while (true) {
        string line;
        getline(in, line);
        if (in.fail()) break;  // fail at EOF
        count++;
    }
    return count;
}

int main() {
    ifstream in;
    while (true) {
        cout << "Enter name: ";
        string s;
        getline(cin, s);
        in.open(s.c_str());  // convert to c style string for in 
        if (!in.fail()) break; 
        cout << "file didn't open, try again\n";
        in.clear();
    }
    cout << "Num lines = " << CountLine(in) << endl;
    return 0;
}