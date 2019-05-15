#include <iostream>

#include "BinarySearchTree.h"
#include "TreeNode.h"


using namespace std;

/*
 * We could cut the runtime of this in half, if we could have the child
 * nodes return their height AND whether they are balanced
 *
 */
bool is_balanced(const TreeNode<int>* node) {
    if (!node) {
        return true;
    }

    int left_height = 0;
    int right_height = 0;

    auto left_child = node->get_left();
    auto right_child = node->get_right();

    if (left_child) {
        left_height = left_child->height();
    }

    if (right_child) {
        right_height = right_child->height();
    }

    if (abs(left_height - right_height) > 1) {
        return false;
    }

    return is_balanced(left_child) && is_balanced(right_child);
}

int main() {
    const vector<int> sorted_array {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    BinarySearchTree<int> tree1 {};
    for (auto i : sorted_array) {
        tree1.add(i);
    }
    cout << "Height of tree1: " << tree1.height() << "\n" << endl;
    cout << "Is balanced? " << is_balanced(tree1.get_head()) << endl;
    cout << endl;

    BinarySearchTree<int> tree2 {};
    tree2.add_sorted_array(sorted_array);
    cout << "Height of tree2: " << tree2.height() << "\n" << endl;
    cout << "Is balanced? " << is_balanced(tree2.get_head()) << endl;
    cout << endl;

    BinarySearchTree<int> tree3 {};
    tree3.add_sorted_array({
            2, 5, 7, 10, 12, 15, 17, 20, 22, 25, 27, 30, 32, 35, 37});
    cout << "Height of tree3: " << tree3.height() << "\n" << endl;
    cout << "Is balanced? " << is_balanced(tree3.get_head()) << endl;
    cout << endl;
}

