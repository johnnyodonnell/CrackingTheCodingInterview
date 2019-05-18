#include <iostream>
#include <vector>

#include "HashTable.h"


using namespace std;

int main() {
    HashTable<int, int> table {10};

    /*
     * insert can take both rvalue and lvalue references
     */
    int i = 1;
    table.insert(i, -1);
    table.insert(2, -2);

    vector<int> vec {1, 2, 3, 4, 5, 6, 7, 8, 9};
    for (auto i : vec) {
        table.insert(i, 100 + i);
    }

    for (auto i : vec) {
        cout << table.find(i) << ", ";
    }
    cout << endl;

    table = {10};
    for (int i = 0; i < 10000; i++) {
        table.insert(i, -i);
    }

    for (int i = 0; i < 10000; i++) {
        cout << table.find(i) << ", ";
    }
    cout << endl;
}

