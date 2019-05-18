#include <iostream>

#include "CircularArray.h"


using namespace std;

int main() {
    CircularArray<int> arr {};

    for (auto i : {1, 2, 3, 4, 5, 6, 7, 8, 9}) {
        arr.push_back(i);
    }

    for (auto i : arr) {
        cout << i << ", ";
    }
    cout << endl;

    arr.rotate(5);

    for (auto i : arr) {
        cout << i << ", ";
    }
    cout << endl;

    arr.rotate(3);

    for (auto i : arr) {
        cout << i << ", ";
    }
    cout << endl;
}

