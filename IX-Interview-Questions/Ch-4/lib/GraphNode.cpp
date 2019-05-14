// https://stackoverflow.com/a/495056/5832619

template <typename T>
GraphNode<T>::GraphNode(const T& c_value) :value{c_value} {}

template <typename T>
const std::vector<GraphNode<T>*>& GraphNode<T>::get_neighbors() {
    return neighbors;
}

template <typename T>
void GraphNode<T>::add_neighbor(GraphNode<T>* node) {
    neighbors.push_back(node);
}

