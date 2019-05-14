#include <iostream>
#include <stack>
#include <forward_list>


using namespace std;

template <typename T>
class MyStack : public stack<T> {
    private:
        forward_list<T> min_list {};

    public:
        void push(const T& val) {
            if (min_list.empty() || (val < min_list.front())) {
                min_list.push_front(val);
            }

            stack<T>::push(val);
        }

        void pop() {
            if (stack<T>::top() == min_list.front()) {
                min_list.pop_front();
            }

            stack<T>::pop();
        }

        T& min() {
            return min_list.front();
        }
};

int main() {
    MyStack<int> myStack {};
    for (auto i : {5, 6, 2, 19, 20, 4, 1, 3, 10, 11}) {
        cout << i << ", ";
        myStack.push(i);
    }
    cout << endl << endl;

    cout << "Min: " << myStack.min() << endl;
    cout << "Top: " << myStack.top() << endl;
    cout << endl;

    for (int i = 0; i < 4; i++) {
        myStack.pop();
    }

    cout << "Min: " << myStack.min() << endl;
    cout << "Top: " << myStack.top() << endl;
    cout << endl;

    for (int i = 0; i < 2; i++) {
        myStack.pop();
    }

    cout << "Min: " << myStack.min() << endl;
    cout << "Top: " << myStack.top() << endl;
    cout << endl;

    for (int i = 0; i < 2; i++) {
        myStack.pop();
    }

    cout << "Min: " << myStack.min() << endl;
    cout << "Top: " << myStack.top() << endl;
    cout << endl;
}

