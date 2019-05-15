// https://stackoverflow.com/a/495056/5832619

template <typename T>
TreeNode<T>::TreeNode(const T& c_value) :value{c_value} {}

template <typename T>
TreeNode<T>* TreeNode<T>::get_left() {
    return children.first;
}

template <typename T>
TreeNode<T>* TreeNode<T>::get_right() {
    return children.second;
}

template <typename T>
void TreeNode<T>::set_left(TreeNode<T>* left) {
    children.first = left;
}

template <typename T>
void TreeNode<T>::set_right(TreeNode<T>* right) {
    children.second = right;
}

template <typename T>
const T& TreeNode<T>::get_value() {
    return value;
}

