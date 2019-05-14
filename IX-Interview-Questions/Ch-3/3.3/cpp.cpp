#include <iostream>
#include <stack>
#include <vector>


using namespace std;

template <typename T>
class SetOfStacks {
    private:
        size_t capacity;
        vector<stack<T>> stacks {{}};

    public:
        SetOfStacks(const size_t c_capacity) :capacity{c_capacity} {}

        void push(const T& value) {
            auto& stack = stacks[stacks.size() - 1];
            if (stack.size() < capacity) {
                stack.push(value);
            } else {
                std::stack<T> new_stack {};
                new_stack.push(value);
                stacks.push_back(new_stack);
            }
        }

        void pop() {
            pop(stacks.size() - 1);
        }

        void pop(const int i) {
            auto& stack = stacks.at(i);
            stack.pop();

            if (stack.empty()) {
                if (i == (stacks.size() - 1)) {
                    stacks.pop_back();
                } else {
                    stacks.erase(stacks.begin() + i);
                }
            }
        }

        T& top() {
            top(stacks.size() - 1);
        }

        T& top(const int i) {
            auto& stack = stacks.at(i);
            return stack.top();
        }
};

int main() {
    SetOfStacks<int> stacks {3};
    for (auto i : {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}) {
        stacks.push(i);
    }

    cout << stacks.top(0) << endl;
    cout << stacks.top(1) << endl;
    cout << stacks.top(2) << endl;
    cout << stacks.top() << endl;
    cout << endl;

    stacks.pop();
    stacks.pop(1);
    cout << stacks.top(1) << endl;
    cout << stacks.top(2) << endl;
    cout << stacks.top() << endl;
}

