#include <iostream>
#include <fstream>
#include <set>

using namespace std;

struct studentT {
    string first, last;
    int idNum;
};

struct CmpById {
    int operator() (studentT a, studentT b) {
        if (a.idNum == b.idNum) return 0;
        if (a.idNum < b.idNum) return -1;
        else return 1;
    }
};

int CompareStudent(studentT a, studentT b) {
    if (a.idNum == b.idNum) return 0;
    if (a.idNum < b.idNum) return -1;
    else return 1;
}

int main() {
    set<studentT, CmpById> s; // supplying callback function
    set<studentT, int(*)(studentT a, studentT b)> t(&CompareStudent);  // another method

    return 0;
}
