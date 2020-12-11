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

//  ent and first bring in as copy, so the effect of second line doesn't stick
// so need & for first, becomre reference of listHead
void Prepend(Entry *ent, Entry * &first) {
    ent->next = first;
    first = ent;  // Buggy
}

Entry *BuildAddressBook() {
    Entry *listHead = NULL;
    while (true) {
        Entry *newOne = GetNewEntry();
        if (newOne == NULL) break;
        Prepend(newOne, listHead);
    }
    return listHead;
}

void InsertSorted(Entry * &list, Entry * newOne) {
    // Traverse list to find the position to insert
    Entry *cur, *prev = NULL;
    for (cur=list; cur!=NULL; cur=cur->next) {
        if (newOne->name < cur->name) break;
        prev = cur;
    }

    newOne->next = cur;  // splice outgoing ptr
    if (prev != NULL)
        prev->next = newOne;  // splice incoming ptr
    else
        list = newOne;  // note special case, at listHead
}

void RecInsertSorted(Entry * &list, Entry * newOne) {
    if (list == NULL || newOne->name < list->name) {
        newOne->next = list;
        list = newOne;
    } else {
        RecInsertSorted(list->next, newOne);
    }
}

int main() {

    return 0;
}