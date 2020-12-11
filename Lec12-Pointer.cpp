#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct Entry {
    string name, phone;
    Entry *next;
};

void PrintEntry(Entry *e) {
    cout << e->name << " " << e->phone << endl;
}

Entry *GetNewEntry() {
    cout << "Enter name (ENTER to quit):";
    string name;
    getline(cin, name);
    if (name == "") return NULL;

    Entry *newOne = new Entry;
    newOne->name = name; // (*newOne).name  dot has precedence over *
    cout << "Enter phone: ";
    getline(cin, newOne->phone);
    newOne->next = NULL;  // no one follow
    return newOne;
}

Entry *BuildList() {
    Entry *list = NULL;
    while (true) {
        Entry *newOne = GetNewEntry();
        if (newOne == NULL) break;
        newOne->next = list; // newOne points to head of list
        list = newOne;  // list now start with newOne
    }
    return list;
}

void PrintList(Entry *list) {
    for (Entry *cur = list; cur != NULL; cur = cur->next) {
        PrintEntry(cur);
    }
}

void RecPrintList(Entry *list) {
    if (list != NULL) {
        RecPrintList(list->next);
        PrintEntry(list);
    }
}

int Count(Entry *list) {
    if (list == NULL) return 0;
    return 1 + Count(list->next);
}

void Deallocate(Entry *list) {
    // when main() exit program will deallocate memory cells
    // manually deallocate is for the program that doesn't exit, e.g in a long running program
    if (list != NULL) {
        Deallocate(list->next);
        delete list;
    }
}

int main() {
    Entry *n = BuildList();
    RecPrintList(n);
    cout << Count(n) << endl;
    return 0;
}