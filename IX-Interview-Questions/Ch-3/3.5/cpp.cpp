#include <iostream>
#include <stack>


using namespace std;

template <typename T, typename F1, typename F2>
T transfer(stack<T>& source, stack<T>& target, F1 loop_pred, F2 keep_pred) {
    auto top = source.top();

    T keep = top;
    source.pop();

    while (loop_pred(top)) {
        top = source.top();

        if (keep_pred(top, keep)) {
            target.push(keep);
            keep = top;
        } else {
            target.push(top);
        }

        source.pop();
    }

    source.push(keep);

    return keep;
}

/*
 * Runs O(n^2)
 *
 */
template <typename T>
void sort_stack(stack<T>& stk) {
    if (stk.empty()) {
        return;
    }

    stack<T> helper_stk {};

    T stk_end = transfer(
            stk, helper_stk,
            [&stk](T top) { return !stk.empty(); },
            greater<T>{});

    if (helper_stk.empty()) {
        return;
    }

    T helper_stk_end = transfer(
            helper_stk, stk,
            [&helper_stk](T top) { return !helper_stk.empty(); },
            less<T>{});

    while ((stk.top() != stk_end)
            && (helper_stk.top() != helper_stk_end)) {
        stk_end = transfer(
                stk, helper_stk,
                [&stk_end](T top) { return top != stk_end; },
                greater<T>{});

        helper_stk_end = transfer(
                helper_stk, stk,
                [&helper_stk_end](T top) { return top != helper_stk_end; },
                less<T>{});
    }

    while (!helper_stk.empty()) {
        stk.push(helper_stk.top());
        helper_stk.pop();
    }
}

template <typename T>
void print_stack(const stack<T>& stk) {
    stack<T> stk_copy {stk};
    while (!stk_copy.empty()) {
        cout << stk_copy.top() << ", ";
        stk_copy.pop();
    }
    cout << endl;
}

int main() {
    stack<int> stk {};
    for (auto i : {6, 3, 8, 8, 2, 3, 10}) {
        stk.push(i);
    }

    print_stack(stk);
    sort_stack(stk);
    print_stack(stk);

    // Sanity checks
    stack<int> empty_stack {};
    sort_stack(empty_stack);

    stack<int> short_stack {};
    short_stack.push(1);
    sort_stack(short_stack);
    short_stack.push(2);
    sort_stack(short_stack);
}

