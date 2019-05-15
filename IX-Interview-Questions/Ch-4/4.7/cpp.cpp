#include <iostream>
#include <unordered_set>

#include "GraphNode.h"


using namespace std;

template <typename T>
class DependencyGraph {
    private:
        vector<const GraphNode<T>*> projects {};

        void build_proj(
                const GraphNode<T>* proj,
                unordered_set<const GraphNode<T>*>& build_projects) {
            if (build_projects.count(proj) > 0) {
                return;
            }

            auto neighbors = proj->get_neighbors();

            if (neighbors.size() > 0) {
                for (auto proj : neighbors) {
                    build_proj(proj, build_projects);
                }
            }

            cout << proj->get_value() << ", ";
            build_projects.insert(proj);
        }

    public:
        void add_project(const GraphNode<T>* proj) {
            projects.push_back(proj);
        }

        /*
         * Does not handle circular dependencies
         *
         */
        void print_build_order() {
            unordered_set<const GraphNode<T>*> built_projects {};

            for (auto proj : projects) {
                build_proj(proj, built_projects);
            }
            cout << endl;
        }
};

/*
 * base depends on dependent
 */
template <typename T>
void dependent(GraphNode<T>* dependent, GraphNode<T>* base) {
    base->add_neighbor(dependent);
}

int main() {
    DependencyGraph<char> graph {};

    auto proj_a = new GraphNode<char>('a');
    auto proj_b = new GraphNode<char>('b');
    auto proj_c = new GraphNode<char>('c');
    auto proj_d = new GraphNode<char>('d');
    auto proj_e = new GraphNode<char>('e');
    auto proj_f = new GraphNode<char>('f');

    graph.add_project(proj_a);
    graph.add_project(proj_b);
    graph.add_project(proj_c);
    graph.add_project(proj_d);
    graph.add_project(proj_e);
    graph.add_project(proj_f);

    dependent(proj_a, proj_d);
    dependent(proj_f, proj_b);
    dependent(proj_b, proj_d);
    dependent(proj_f, proj_a);
    dependent(proj_d, proj_c);

    graph.print_build_order();
}

