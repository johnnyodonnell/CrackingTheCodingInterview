#include <iostream>
#include <vector>
#include <set>

/*
 * Using a set instead of a vector, eliminates duplciates
 * but increases insert time
 *
 */

using namespace std;

template <typename T>
void power_set(const set<T>& st, set<set<T>>& result) {
    result.insert(st);

    if (st.size()) {

        for (auto& val : st) {
            auto subset = st;
            subset.erase(val);
            power_set(subset, result);
        }
    }
}

template <typename T>
set<set<T>> power_set(const set<T>& st) {
    set<set<T>> result {};
    power_set(st, result);
    return result;
}

int main() {
    set<int> st {1, 2, 2, 3, 5,};
    auto result = power_set(st);
    for (auto& st : result) {
        cout << "{";
        for (auto val : st) {
            cout << val << ", ";
        }
        cout << "}" << endl;
    }
}

