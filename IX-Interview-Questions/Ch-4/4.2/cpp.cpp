#include <iostream>
#include <vector>

#include "TreeNode.h"


using namespace std;

template <typename T>
class BinarySearchTree {
    private:
        TreeNode<T>* head = nullptr;

        int height(TreeNode<T>* node) {
            if (node) {
                return 1 +
                    max(height(node->get_left()), height(node->get_right()));
            } else {
                return 0;
            }
        }

    public:
        void add(const T& value) {
            auto new_node = new TreeNode<T>(value);

            if (!head) {
                head = new_node;
                return;
            }

            auto current_node = head;
            while (current_node) {
                if (value < current_node->get_value()) {
                    auto left_child = current_node->get_left();
                    if (left_child) {
                        current_node = left_child;
                    } else {
                        current_node->set_left(new_node);
                        return;
                    }
                } else {
                    auto right_child = current_node->get_right();
                    if (right_child) {
                        current_node = right_child;
                    } else {
                        current_node->set_right(new_node);
                        return;
                    }
                }
            }
        }

        int height() {
            return height(head);
        }
};

template <typename T>
void add_sorted_array(
        BinarySearchTree<T>& tree,
        typename vector<T>::const_iterator begin,
        typename vector<T>::const_iterator end) {
    if (begin == end) {
        return;
    }

    size_t length = end - begin;
    size_t midpoint = length / 2;

    auto p = begin + midpoint;
    cout << *p << endl;
    tree.add(*p);

    add_sorted_array(tree, begin, begin + midpoint);
    add_sorted_array(tree, begin + midpoint + 1, end);
}

template <typename T>
void add_sorted_array(
        BinarySearchTree<T>& tree, const vector<T>& sorted_array) {
    add_sorted_array(tree, sorted_array.begin(), sorted_array.end());
}

int main() {
    const vector<int> sorted_array {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    BinarySearchTree<int> tree1 {};
    for (auto i : sorted_array) {
        tree1.add(i);
    }
    cout << "Height of tree1: " << tree1.height() << "\n" << endl;

    BinarySearchTree<int> tree2 {};
    add_sorted_array(tree2, sorted_array);
    cout << "Height of tree2: " << tree2.height() << "\n" << endl;
}

