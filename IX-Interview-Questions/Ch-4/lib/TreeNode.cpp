// https://stackoverflow.com/a/495056/5832619

template <typename T>
TreeNode<T>::TreeNode(const T& c_value) :value{c_value} {}

template <typename T>
TreeNode<T>* TreeNode<T>::get_left() const {
    return children.first;
}

template <typename T>
TreeNode<T>* TreeNode<T>::get_right() const {
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
const T& TreeNode<T>::get_value() const {
    return value;
}

template <typename T>
int TreeNode<T>::height() const {
    int left_height = 0;
    int right_height = 0;

    if (children.first) {
        left_height = children.first->height();
    }

    if (children.second) {
        right_height = children.second->height();
    }

    return 1 + std::max(left_height, right_height);
}

