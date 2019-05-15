

template <typename T>
class TreeNode {
    private:
        T value;
        std::pair<TreeNode*, TreeNode*> children {};

    public:
        TreeNode(const T&);

        TreeNode<T>* get_left();

        void set_left(TreeNode<T>*);

        TreeNode<T>* get_right();

        void set_right(TreeNode<T>*);

        const T& get_value();
};

// https://stackoverflow.com/a/495056/5832619
#include "TreeNode.cpp"

