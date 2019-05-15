#include <iostream>
#include <vector>
#include <list>

#include "BinarySearchTree.h"
#include "TreeNode.h"


using namespace std;

template <typename T>
void merge(
        const vector<T>& left, int left_i,
        const vector<T>& right, int right_i,
        vector<vector<T>>& results,
        vector<T>&& working_vector) {
    if ((left_i >= left.size()) && (right_i >= right.size())) {
        results.push_back(working_vector);
    } else if (left_i >= left.size()) {
        for (int i = right_i; i < right.size(); i++) {
            working_vector.push_back(right.at(i));
        }
        results.push_back(working_vector);
    } else if (right_i >= right.size()) {
        for (int i = left_i; i < left.size(); i++) {
            working_vector.push_back(left.at(i));
        }
        results.push_back(working_vector);
    } else {
        vector<T> working_vector_copy {working_vector};

        working_vector.push_back(left[left_i]);
        merge(left, left_i + 1,
                right, right_i, results, move(working_vector));

        working_vector_copy.push_back(right[right_i]);
        merge(left, left_i,
                right, right_i + 1, results, move(working_vector_copy));
    }
}

/*
 * Contains some duplicates... actually, it doesn't surprisingly
 *
 */
template <typename T>
vector<vector<T>> possible_arrays(const TreeNode<T>* node) {
    if (node) {
        auto left_child = node->get_left();
        auto right_child = node->get_right();

        auto left_vecs = possible_arrays(left_child);
        auto right_vecs = possible_arrays(right_child);

        vector<vector<T>> merged_vecs {};

        for (auto& left_vec : left_vecs) {
            for (auto& right_vec : right_vecs) {
                merge(left_vec, 0,
                        right_vec, 0, merged_vecs, {node->get_value()});
            }
        }

        return merged_vecs;
    } else {
        vector<vector<T>> result {};
        result.push_back({});
        return result;
    }
}

template <typename T>
void print(const vector<vector<T>>& vecs) {
    for (auto& vec : vecs) {
        for (auto i : vec) {
            cout << i << ", ";
        }
        cout << endl;
    }
    cout << endl;
}

int main() {
    BinarySearchTree<int> tree {};
    for (auto i : {2, 1, 3}) {
        tree.add(i);
    }

    auto vecs = possible_arrays(tree.get_head());
    print(vecs);

    tree = {};
    for (auto i : {5, 3, 2, 4, 4}) {
        tree.add(i);
    }

    vecs = possible_arrays(tree.get_head());
    print(vecs);

    tree = {};
    for (auto i : {4, 2, 1, 3, 5}) {
        tree.add(i);
    }

    vecs = possible_arrays(tree.get_head());
    print(vecs);

    tree = {};
    for (auto i : {6, 7, 2, 4, 7, 2, 10, 11, 6, 2}) {
        tree.add(i);
    }

    vecs = possible_arrays(tree.get_head());
    print(vecs);
}

/*
    4
   / \
  2   5
 / \   \
1   3   6

merge {2, 1, 3} and {5, 6}

{5, 2, 1, 3}
{5, 6, 2, 1, 3}
{5, 2, 6, 1, 3}
{5, 2, 1, 6, 3}
{5, 2, 1, 3, 6}

{2, 5, 1, 3}

{2, 1, 5, 3}

{2, 1, 3, 5}
{2, 1, 3, 5, 6}
*/

