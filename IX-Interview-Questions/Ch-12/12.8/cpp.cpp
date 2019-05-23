#include <iostream>
#include <queue>
#include <unordered_set>
#include <functional>


using namespace std;

class Node {
    private:
        int val;
        Node* left;
        Node* right;

    public:
        Node(int c_val, Node* c_left, Node* c_right)
            :val{c_val}, left{c_left}, right{c_right} {}

        int get_val() {
            return val;
        }

        void set_val(int m_val) {
            val = m_val;
        }

        Node* get_left() {
            return left;
        }

        void set_left(Node* m_left) {
            left = m_left;
        }

        Node* get_right() {
            return right;
        }

        void set_right(Node* m_right) {
            right = m_right;
        }

        Node* deep_copy() {
            Node* left_copy = nullptr;
            Node* right_copy = nullptr;

            if (left) {
                left_copy = left->deep_copy();
            }

            if (right) {
                right_copy = right->deep_copy();
            }

            return new Node(val, left_copy, right_copy);
        }

        void apply(const function<void(Node*)> func) {
            func(this);
            if (left) {
                left->apply(func);
            }

            if (right) {
                right->apply(func);
            }
        }

        void print() {
            queue<Node*> nodes {};
            nodes.push(this);

            unordered_set<Node*> rightmost_nodes {};
            rightmost_nodes.insert(this);

            while (!nodes.empty()) {
                auto node = nodes.front();
                nodes.pop();

                cout << node->get_val() << ", ";

                if (node->left) {
                    nodes.push(node->left);
                }

                if (node->right) {
                    nodes.push(node->right);
                }

                if (rightmost_nodes.count(node)) {
                    cout << endl;

                    if (node->right) {
                        rightmost_nodes.insert(node->right);
                    }
                }
            }

            cout << endl;
        }
};

int main() {
    auto n = new Node(10,
            new Node(5,
                new Node(2, nullptr, nullptr),
                new Node(7, nullptr, nullptr)),
            new Node(15,
                new Node(12, nullptr, nullptr),
                new Node(17, nullptr, nullptr)));
    auto n2 = n->deep_copy();

    n2->apply([](Node* n) {
            n->set_val(n->get_val() * 2);
            });

    n->print();
    n2->print();
}

