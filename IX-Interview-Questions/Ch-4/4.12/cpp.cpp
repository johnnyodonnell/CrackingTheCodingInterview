#include <iostream>

#include "BinarySearchTree.h"
#include "TreeNode.h"


using namespace std;

int num_of_paths_with_sum(
        const TreeNode<int>* node, int target_sum, int current_sum = 0) {
    if (node) {
        auto value = node->get_value();
        current_sum += value;

        int result = 0;

        if (current_sum == target_sum) {
            result++;
        }

        return result +
            num_of_paths_with_sum(node->get_left(), target_sum, current_sum) +
            num_of_paths_with_sum(node->get_right(), target_sum, current_sum);
    } else {
        return 0;
    }
}

int main() {
    BinarySearchTree<int> tree {};
    for (auto i : {4, 6, 7, 2, 1, 3}) {
        tree.add(i);
    }

    for (auto target :
            {20, 19, 18, 17, 16, 15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5}) {
        cout << num_of_paths_with_sum(tree.get_head(), target) << endl;
    }
}

