#include <iostream>
#include <stack>


using namespace std;

template <typename T>
class MyQueue {
    private:
        stack<T> incoming {};
        stack<T> outgoing {};

        void transfer() {
            while (!incoming.empty()) {
                outgoing.push(incoming.top());
                incoming.pop();
            }
        }

    public:
        void push(const T& value) {
            incoming.push(value);
        }

        T& front() {
            if (outgoing.empty()) {
                transfer();
            }

            return outgoing.top();
        }

        void pop() {
            if (outgoing.empty()) {
                transfer();
            }

            outgoing.pop();
        }

        bool empty() {
            return incoming.empty() && outgoing.empty();
        }
};

int main() {
    MyQueue<int> q {};
    for (auto i : {1, 2, 3, 4, 5, 6, 7, 8}) {
        q.push(i);
    }

    for (int i = 0; i < 3; i++) {
        cout << q.front() << ", ";
        q.pop();
    }
    cout << endl;

    for (auto i : {9, 10 , 11, 12}) {
        q.push(i);
    }

    while (!q.empty()) {
        cout << q.front() << ", ";
        q.pop();
    }
    cout << endl;
}

