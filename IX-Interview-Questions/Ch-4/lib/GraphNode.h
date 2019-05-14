#include <vector>


template <typename T>
class GraphNode {
    private:
        T value;
        std::vector<GraphNode*> neighbors;

    public:
        GraphNode() = default;
        GraphNode(const T&);

        const std::vector<GraphNode*>& get_neighbors();

        void add_neighbor(GraphNode*);
};

// https://stackoverflow.com/a/495056/5832619
#include "GraphNode.cpp"

