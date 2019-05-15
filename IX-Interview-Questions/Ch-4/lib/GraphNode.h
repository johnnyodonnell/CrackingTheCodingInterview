#include <vector>


template <typename T>
class GraphNode {
    private:
        T value;
        std::vector<GraphNode*> neighbors {};

    public:
        GraphNode(const T&);

        const std::vector<GraphNode*>& get_neighbors() const;

        void add_neighbor(GraphNode*);

        const T& get_value() const;
};

// https://stackoverflow.com/a/495056/5832619
#include "GraphNode.cpp"

