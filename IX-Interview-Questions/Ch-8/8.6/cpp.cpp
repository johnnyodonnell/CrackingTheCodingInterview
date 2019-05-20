#include <iostream>
#include <stack>


using namespace std;

template <typename T>
void print_stack(stack<T> stk) {
    while (!stk.empty()) {
        cout << stk.top() << ", ";
        stk.pop();
    }
    cout << endl;
}

template <typename T>
void move_stack(
        stack<T>& source, int source_size,
        stack<T>& target, int target_size,
        stack<T>& helper, int helper_size) {
    if (source_size <= 0) {
        return;
    } else if ((source_size % 2) == 0) {
        helper.push(source.top());
        source.pop();

        move_stack(
                target, target_size,
                helper, 0,
                source, 0);
        move_stack(
                source, source_size - 1,
                target, 0,
                helper, helper_size + target_size + 1);
    } else {
        target.push(source.top());
        source.pop();

        move_stack(
                helper, helper_size,
                target, 0,
                source, 0);
        move_stack(
                source, source_size - 1,
                target, target_size + helper_size + 1,
                helper, 0);
    }
}

template <typename T>
void move_stack(stack<T>& source, stack<T>& target) {
    stack<T> helper {};
    move_stack(
            source, source.size(),
            target, 0,
            helper, 0);
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

