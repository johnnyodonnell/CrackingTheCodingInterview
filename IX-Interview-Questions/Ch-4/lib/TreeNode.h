#ifndef TREE_NODE_H
#define TREE_NODE_H

template <typename T>
class TreeNode {
    private:
        T value;
        std::pair<TreeNode*, TreeNode*> children {};

    public:
        TreeNode(const T&);

        TreeNode<T>* get_left() const;

        void set_left(TreeNode<T>*);

        TreeNode<T>* get_right() const;

        void set_right(TreeNode<T>*);

        const T& get_value() const;

        int height() const;
};

// https://stackoverflow.com/a/495056/5832619
#include "TreeNode.cpp"

#endif

