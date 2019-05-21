#include <iostream>
#include <stack>


using namespace std;

template <typename T>
void move_stack(
        stack<T>& source, int source_size,
        stack<T>& target, stack<T>& helper) {
    if (source_size <= 0) {
        return;
    } else {
        move_stack(source, source_size - 1, helper, target);
        target.push(source.top());
        source.pop();
        move_stack(helper, source_size - 1, target, source);
    }
}

template <typename T>
void move_stack(stack<T>& source, stack<T>& target) {
    stack<T> helper {};
    move_stack(source, source.size(), target, helper);
}

int main() {
    stack<int> source {};
    stack<int> target {};

    for (int i = 2; i < 10; i++) {
        source =  {};
        for (int j = i; j > 0; j--) {
            source.push(j);
        }

        target = {};
        move_stack(source, target);
        while (!target.empty()) {
            cout << target.top() << ", ";
            target.pop();
        }
        cout << endl;
    }
}

