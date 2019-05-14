#include <iostream>
#include <queue>
#include <unordered_set>

#include "GraphNode.h"


using namespace std;

template <typename T>
bool route_between(GraphNode<T>* start, GraphNode<T>* end) {
    queue<GraphNode<T>*> node_q {};
    node_q.push(start);

    unordered_set<GraphNode<T>*> marked_nodes {};

    while (!node_q.empty()) {
        auto node = node_q.front();

        if (node == end) {
            return true;
        }

        for (auto neighbor : node->get_neighbors()) {
            if (marked_nodes.count(neighbor) == 0) {
                node_q.push(neighbor);
                marked_nodes.insert(neighbor);
            }
        }

        node_q.pop();
    }

    return false;
}

int main() {
    // Cloning graph from p. 107
    auto node0 = new GraphNode<int>{0};
    auto node1 = new GraphNode<int>{1};
    auto node2 = new GraphNode<int>{2};
    auto node3 = new GraphNode<int>{3};
    auto node4 = new GraphNode<int>{4};
    auto node5 = new GraphNode<int>{5};

    node0->add_neighbor(node1);
    node0->add_neighbor(node4);
    node0->add_neighbor(node5);

    node1->add_neighbor(node3);
    node1->add_neighbor(node4);

    node2->add_neighbor(node1);

    node3->add_neighbor(node2);
    node3->add_neighbor(node4);

    cout << route_between(node0, node4) << endl;
    cout << route_between(node2, node5) << endl;
}

