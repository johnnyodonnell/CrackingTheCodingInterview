#include <iostream>
#include <vector>

#include "TreeNode.h"
#include "BinarySearchTree.h"


using namespace std;

TreeNode<int>* min(TreeNode<int>* node) {
    auto left_child = node->get_left();

    if (left_child) {
        return min(left_child);
    } else {
        return node;
    }
}

TreeNode<int>* successor(TreeNode<int>* node) {
    auto right_child = node->get_right();

    if (right_child) {
        return min(right_child);
    }

    auto value = node->get_value();
    auto parent = node->get_parent();
    while (parent) {
        // >= vs. > depends on the rules of the BST
        if (parent->get_value() >= value) {
            return parent;
        }

        parent = parent->get_parent();
    }

    return nullptr;
}

int main() {
    const vector<int> sorted_array {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
    BinarySearchTree<int> bst {};
    bst.add_sorted_array(sorted_array);

    auto node = bst.get_head();
    while (node) {
        cout << node->get_value() << ", ";
        node = successor(node);
    }
    cout << endl;
}

