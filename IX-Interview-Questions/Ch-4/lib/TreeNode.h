#ifndef TREE_NODE_H
#define TREE_NODE_H

/*
 * A more accurate name for this class would be BinaryNode
 *
 */
template <typename T>
class TreeNode {
    private:
        TreeNode<T>* parent = nullptr;
        T value;
        std::pair<TreeNode*, TreeNode*> children {};

    public:
        TreeNode(const T&);

        TreeNode<T>* get_left() const;

        void set_left(TreeNode<T>*);

        TreeNode<T>* get_right() const;

        void set_right(TreeNode<T>*);

        TreeNode<T>* get_parent() const;

        const T& get_value() const;

        int height() const;
};

// https://stackoverflow.com/a/495056/5832619
#include "TreeNode.cpp"

#endif

