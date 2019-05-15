#include <iostream>
#include <vector>

#include "BinarySearchTree.h"
#include "TreeNode.h"


using namespace std;

template <typename T>
class BSTRand : public BinarySearchTree<T> {
    private:
        vector<TreeNode<T>*> nodes {};

    public:
        void add(const T& value) {
            auto new_node = new TreeNode<T>(value);

            // Needed for getRandomNode()
            nodes.push_back(new_node);

            BinarySearchTree<T>::add(value, new_node);
        }

        /*
         * Increases runtime of remove from O(log2(n)) to O(n)
         *
         */
        void remove(const T& value) {
            auto node = BinarySearchTree<T>::find(value);

            // Needed for getRandomNode()
            for (auto p  = nodes.begin(); p != nodes.end(); p++) {
                if (*p == node) {
                    nodes.erase(p);
                    break;
                }
            }

            BinarySearchTree<T>::remove(node);
        }

        TreeNode<T>* get_random_node() {
            int index = rand() % nodes.size();
            return nodes.at(index);
        }
};

int main() {
    BSTRand<int> tree {};
    for (auto i : {4, 6, 7, 2, 1, 3}) {
        tree.add(i);
    }

    for (int i = 0; i < 10; i++) {
        cout << tree.get_random_node()->get_value() << endl;
    }
    cout << endl;

    auto node1 = tree.find(1);
    cout << node1 << " : " << node1->get_value() << endl;

    tree.remove(1);
    node1 = tree.find(1);
    if (!node1) {
        cout << "Couldn't find!" << endl;
    }

    tree.remove(4);
    auto node4 = tree.find(4);
    if (!node4) {
        cout << "Couldn't find!" << endl;
    }
    cout << endl;

    for (int i = 0; i < 10; i++) {
        cout << tree.get_random_node()->get_value() << endl;
    }
}

