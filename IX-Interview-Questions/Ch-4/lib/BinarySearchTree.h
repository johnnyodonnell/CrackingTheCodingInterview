#include <vector>

#include "TreeNode.h"


template <typename T>
class BinarySearchTree {
    private:
        TreeNode<T>* head = nullptr;

    protected:
        void add(const T&, TreeNode<T>*, TreeNode<T>*);
        void add(const T&, TreeNode<T>*);
        void remove(TreeNode<T>*);

    public:
        virtual void add(const T&);
        int height();
        void add_sorted_array(
                typename std::vector<T>::const_iterator,
                typename std::vector<T>::const_iterator);
        void add_sorted_array(const std::vector<T>&);
        TreeNode<T>* get_head();
        TreeNode<T>* find(const T&);
        virtual void remove(const T&);
};

#include "BinarySearchTree.cpp"

