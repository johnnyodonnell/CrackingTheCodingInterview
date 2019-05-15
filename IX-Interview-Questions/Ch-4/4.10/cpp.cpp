#include <iostream>

#include "TreeNode.h"
#include "BinarySearchTree.h"


using namespace std;

template <typename T>
bool equal(const TreeNode<T>* tree_a, const TreeNode<T>* tree_b) {
    if (!tree_a && !tree_b) {
        return true;
    } else if (tree_a && tree_b) {
        return (tree_a->get_value() == tree_b->get_value())
            && equal(tree_a->get_left(), tree_b->get_left())
            && equal(tree_a->get_right(), tree_b->get_right());
    } else {
        return false;
    }
}

template <typename T>
bool is_subtree(const TreeNode<T>* super, const TreeNode<T>* sub) {
    if (!super) {
        return false;
    } else if (super->get_value() == sub->get_value()) {
        return equal(super, sub);
    } else {
        return (is_subtree(super->get_left(), sub)
                || is_subtree(super->get_right(), sub));
    };
}

int main() {
    BinarySearchTree<int> tree1 {};
    for (auto i : {4, 6, 7, 2, 1, 3}) {
        tree1.add(i);
    }

    BinarySearchTree<int> tree2 {};
    for (auto i : {2, 1, 3}) {
        tree2.add(i);
    }

    BinarySearchTree<int> tree3 {};
    for (auto i : {2, 4, 1}) {
        tree3.add(i);
    }

    cout << is_subtree(tree1.get_head(), tree2.get_head()) << endl;
    cout << is_subtree(tree1.get_head(), tree3.get_head()) << endl;
}

