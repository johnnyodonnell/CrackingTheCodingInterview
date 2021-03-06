#include <iostream>
#include <vector>
#include <queue>
#include <functional>

#include "TreeNode.h"
#include "BinarySearchTree.h"


using namespace std;

bool is_binary_search_tree(
        const TreeNode<int>* node, int* min = nullptr, int* max = nullptr) {
    if (!node) {
        return true;
    }

    auto value = node->get_value();

    auto left_child = node->get_left();
    auto right_child = node->get_right();

    if (left_child) {
        auto child_value = left_child->get_value();
        if ((child_value > value)
                || (min && (child_value < *min))
                || (max && (child_value > *max))) {
            return false;
        }
    }

    if (right_child) {
        auto child_value = right_child->get_value();
        if ((child_value < value)
                || (min && (child_value < *min))
                || (max && (child_value > *max))) {
            return false;
        }
    }

    return is_binary_search_tree(left_child, min, &value)
        && is_binary_search_tree(right_child, &value, max);
}

TreeNode<int>* make_normal_tree(const vector<int>& vec) {
    if (vec.size() <= 0) {
        return nullptr;
    }

    queue<function<TreeNode<int>* (int)>> node_q {};
    TreeNode<int>* head = nullptr;
    node_q.push([&head](int value) {
                head = new TreeNode<int>{value};
                return head;
            });

    for (int i = 0; i < vec.size(); i++) {
        auto set_value = node_q.front();
        auto node = set_value(vec.at(i));

        node_q.push([node](int value) {
                    auto new_node = new TreeNode<int>{value};
                    node->set_left(new_node);
                    return new_node;
                });

        node_q.push([node](int value) { 
                    auto new_node = new TreeNode<int>{value};
                    node->set_right(new_node);
                    return new_node;
                });

        node_q.pop();
    }

    return head;
}

int main() {
    const vector<int> sorted_array {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
    BinarySearchTree<int> bst {};
    bst.add_sorted_array(sorted_array);
    cout << is_binary_search_tree(bst.get_head()) << endl;

    auto normal_tree = make_normal_tree(sorted_array);
    cout << is_binary_search_tree(normal_tree) << endl;

    auto almost_binary = make_normal_tree({6, 3, 10, 1, 7});
    cout << is_binary_search_tree(almost_binary) << endl;
}

