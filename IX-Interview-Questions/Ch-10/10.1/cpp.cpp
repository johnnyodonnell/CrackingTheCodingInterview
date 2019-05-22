#include <iostream>
#include <vector>
#include <queue>


using namespace std;

/*
 * Runs O(a + b);
 * Space O(a);
 *
 */
template <typename T>
void merge_sorted(vector<T>& sorted_a, vector<T>& sorted_b) {
    queue<T> a_buffer {};

    int index_a = 0;
    int index_b = 0;

    while ((index_a < sorted_a.size()) && (index_b < sorted_b.size())) {
        if (sorted_a[index_a] <= sorted_b[index_b]) {
            ++index_a;
        } else if (!a_buffer.empty()
                && (a_buffer.front() <= sorted_b[index_b])) {
            a_buffer.push(sorted_a[index_a]);
            sorted_a[index_a] = a_buffer.front();
            a_buffer.pop();
            ++index_a;
        } else {
            a_buffer.push(sorted_a[index_a]);
            sorted_a[index_a] = sorted_b[index_b];
            ++index_a;
            ++index_b;
        }
    }

    while (!a_buffer.empty() && (index_b < sorted_b.size())) {
        if (a_buffer.front() <= sorted_b[index_b]) {
            sorted_a.push_back(a_buffer.front());
            a_buffer.pop();
        } else {
            sorted_a.push_back(sorted_b[index_b]);
            ++index_b;
        }
    }

    while (!a_buffer.empty()) {
        sorted_a.push_back(a_buffer.front());
        a_buffer.pop();
    }

    while (index_b < sorted_b.size()) {
        sorted_a.push_back(sorted_b[index_b]);
        index_b++;
    }
}

void run_merge_sorted(vector<int> a, vector<int> b) {
    a.reserve(a.size() + b.size());

    merge_sorted(a, b);

    for (auto& val : a) {
        cout << val << ", ";
    }
    cout << "\n" << endl;
}

int main() {
    run_merge_sorted({1, 2, 3, 4, 5}, {2, 2, 4, 4, 6});
    run_merge_sorted({}, {1, 2, 3});
    run_merge_sorted({1, 2, 3}, {});
}

