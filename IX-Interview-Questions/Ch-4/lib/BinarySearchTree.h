#include <vector>

#include "TreeNode.h"


template <typename T>
class BinarySearchTree {
    private:
        TreeNode<T>* head = nullptr;

    public:
        void add(const T&);
        int height();
        void add_sorted_array(
                typename std::vector<T>::const_iterator,
                typename std::vector<T>::const_iterator);
        void add_sorted_array(const std::vector<T>&);
        TreeNode<T>* get_head();
};

#include "BinarySearchTree.cpp"

