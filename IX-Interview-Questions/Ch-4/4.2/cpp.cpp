#include <iostream>
#include <vector>

#include "BinarySearchTree.h"

/*
 * The solution to this problem (add_sorted_arry) can be found
 * in the BinarySearchTree class
 *
 */

using namespace std;

int main() {
    const vector<int> sorted_array {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    BinarySearchTree<int> tree1 {};
    for (auto i : sorted_array) {
        tree1.add(i);
    }
    cout << "Height of tree1: " << tree1.height() << "\n" << endl;

    BinarySearchTree<int> tree2 {};
    tree2.add_sorted_array(sorted_array);
    cout << "Height of tree2: " << tree2.height() << "\n" << endl;
}

