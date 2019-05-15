#include <iostream>
#include <stack>

#include "TreeNode.h"


using namespace std;

template <typename T>
stack<TreeNode<T>*> get_lineage(TreeNode<T>* node) {
    stack<TreeNode<T>*> result {};

    while (node) {
        result.push(node);
        node = node->get_parent();
    }

    return result;
}

template <typename T>
TreeNode<T>* find_common_ancestor(TreeNode<T>* node_a, TreeNode<T>* node_b) {
    auto lineage_a = get_lineage(node_a);
    auto lineage_b = get_lineage(node_b);

    if (lineage_a.top() != lineage_b.top()) {
        throw "Nodes not from the same tree";
    }

    TreeNode<T>* prev = nullptr;

    while (!lineage_a.empty() && !lineage_b.empty()) {
        auto current_a = lineage_a.top();
        auto current_b = lineage_b.top();

        if (current_a != current_b) {
            return prev;
        }

        prev = current_a;
        lineage_a.pop();
        lineage_b.pop();
    }

    return prev;
}

int main() {
    /*
     * Copying "full binary tree" from p. 102
     */
    auto node_10 = new TreeNode<int>{10};
    auto node_5 = new TreeNode<int>{5};
    auto node_20 = new TreeNode<int>{20};
    auto node_3 = new TreeNode<int>{3};
    auto node_9 = new TreeNode<int>{9};
    auto node_18 = new TreeNode<int>{18};
    auto node_7 = new TreeNode<int>{7};

    node_10->set_left(node_5);
    node_10->set_right(node_20);

    node_20->set_left(node_3);
    node_20->set_right(node_7);

    node_3->set_left(node_9);
    node_3->set_right(node_18);

    cout << find_common_ancestor(node_18, node_7)->get_value() << endl;
    cout << find_common_ancestor(node_18, node_5)->get_value() << endl;
    cout << find_common_ancestor(node_10, node_3)->get_value() << endl;
}

