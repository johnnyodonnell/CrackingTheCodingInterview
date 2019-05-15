
template <typename T>
int BinarySearchTree<T>::height(TreeNode<T>* node) {
    if (node) {
        return 1 +
            std::max(height(node->get_left()), height(node->get_right()));
    } else {
        return 0;
    }
}

template <typename T>
void BinarySearchTree<T>::add(const T& value) {
    auto new_node = new TreeNode<T>(value);

    if (!head) {
        head = new_node;
        return;
    }

    auto current_node = head;
    while (current_node) {
        if (value < current_node->get_value()) {
            auto left_child = current_node->get_left();
            if (left_child) {
                current_node = left_child;
            } else {
                current_node->set_left(new_node);
                return;
            }
        } else {
            auto right_child = current_node->get_right();
            if (right_child) {
                current_node = right_child;
            } else {
                current_node->set_right(new_node);
                return;
            }
        }
    }
}

template <typename T>
int BinarySearchTree<T>::height() {
    return height(head);
}

template <typename T>
void BinarySearchTree<T>::add_sorted_array(
        typename std::vector<T>::const_iterator begin,
        typename std::vector<T>::const_iterator end) {
    if (begin == end) {
        return;
    }

    size_t length = end - begin;
    size_t midpoint = length / 2;

    auto p = begin + midpoint;
    add(*p);

    add_sorted_array(begin, begin + midpoint);
    add_sorted_array(begin + midpoint + 1, end);
}

template <typename T>
void BinarySearchTree<T>::add_sorted_array(
        const std::vector<T>& sorted_array) {
    add_sorted_array(sorted_array.begin(), sorted_array.end());
}

