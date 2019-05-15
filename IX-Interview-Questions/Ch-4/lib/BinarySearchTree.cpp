
template <typename T>
void BinarySearchTree<T>::add(
        const T& value, TreeNode<T>* new_node) {
    if (!head) {
        head = new_node;
        return;
    }

    add(value, new_node, head);
}

template <typename T>
void BinarySearchTree<T>::add(
        const T& value, TreeNode<T>* new_node, TreeNode<T>* base_node) {
    auto current_node = base_node;
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
void BinarySearchTree<T>::add(const T& value) {
    auto new_node = new TreeNode<T>(value);
    add(value, new_node);
}

template <typename T>
int BinarySearchTree<T>::height() {
    return head->height();
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

template <typename T>
TreeNode<T>* BinarySearchTree<T>::get_head() {
    return head;
}

template <typename T>
TreeNode<T>* BinarySearchTree<T>::find(const T& value) {
    auto current = head;

    while (current) {
        auto current_value = current->get_value();

        if (current_value == value) {
            return current;
        } else if (value < current_value) {
            current = current->get_left();
        } else {
            current = current->get_right();
        }
    }

    return nullptr;
}

template <typename T>
void BinarySearchTree<T>::remove(const T& value) {
    auto node = find(value);
    remove(node);
}

template <typename T>
void BinarySearchTree<T>::remove(TreeNode<T>* node) {
    if (node) {
        auto left_child = node->get_left();
        auto right_child = node->get_right();

        /*
         * Favor the right child for this impl, but could potentially
         * check heights first and pick the child with the larger height
         */
        TreeNode<T>* replacement = nullptr;
        if (right_child) {
            replacement = right_child;
            if (left_child) {
                add(left_child->get_value(), left_child, right_child);
            }
        } else {
            replacement = left_child;
        }


        auto parent = node->get_parent();
        if (parent) {
            if (parent->get_left() == node) {
                parent->set_left(replacement);
            } else {
                parent->set_right(replacement);
            }
        } else {
            head = replacement;
        }
    }
}

