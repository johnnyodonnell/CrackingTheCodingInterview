#include <vector>

#include "TreeNode.h"


template <typename T>
class BinarySearchTree {
    private:
        TreeNode<T>* head = nullptr;
        int height(TreeNode<T>*);

    public:
        void add(const T&);
        int height();
        void add_sorted_array(
                typename std::vector<T>::const_iterator,
                typename std::vector<T>::const_iterator);
        void add_sorted_array(const std::vector<T>&);
};

#include "BinarySearchTree.cpp"

