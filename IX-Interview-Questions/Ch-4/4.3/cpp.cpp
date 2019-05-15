#include <iostream>
#include <vector>
#include <list>

#include "BinarySearchTree.h"
#include "TreeNode.h"


using namespace std;

void generate_list_of_depths(
        TreeNode<int>* node,
        int depth,
        vector<list<TreeNode<int>*>>& depth_lists) {
    if (node) {
        if (depth < depth_lists.size()) {
            auto& depth_list = depth_lists.at(depth);
            depth_list.push_back(node);
        } else {
            list<TreeNode<int>*> depth_list {};
            depth_list.push_back(node);
            depth_lists.push_back(depth_list);
        }

        generate_list_of_depths(node->get_left(), depth + 1, depth_lists);
        generate_list_of_depths(node->get_right(), depth + 1, depth_lists);
    }
}

vector<list<TreeNode<int>*>> list_of_depths(TreeNode<int>* node) {
    vector<list<TreeNode<int>*>> depth_lists {};
    generate_list_of_depths(node, 0, depth_lists);
    return depth_lists;
}

void print_list_of_depths(vector<list<TreeNode<int>*>> depth_lists) {
    for (const auto& depth_list : depth_lists) {
        for (auto node : depth_list) {
            cout << node->get_value() << ", ";
        }
        cout << endl;
    }
    cout << endl;
}

int main() {
    const vector<int> sorted_array {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    BinarySearchTree<int> tree1 {};
    for (auto i : sorted_array) {
        tree1.add(i);
    }
    cout << "Height of tree1: " << tree1.height() << "\n" << endl;
    auto depths_list = list_of_depths(tree1.get_head());
    print_list_of_depths(depths_list);

    BinarySearchTree<int> tree2 {};
    tree2.add_sorted_array(sorted_array);
    cout << "Height of tree2: " << tree2.height() << "\n" << endl;
    depths_list = list_of_depths(tree2.get_head());
    print_list_of_depths(depths_list);

    BinarySearchTree<int> tree3 {};
    tree3.add_sorted_array({
            2, 5, 7, 10, 12, 15, 17, 20, 22, 25, 27, 30, 32, 35, 37});
    cout << "Height of tree3: " << tree3.height() << "\n" << endl;
    depths_list = list_of_depths(tree3.get_head());
    print_list_of_depths(depths_list);
}

