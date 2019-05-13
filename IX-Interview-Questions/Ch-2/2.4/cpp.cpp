#include <iostream>
#include <forward_list>
#include <vector>


using namespace std;

/*
 * Runs O(n)
 *
 */
void partition(forward_list<int>& flist, int value) {
    forward_list<int>::iterator prev {};
    auto current = flist.begin();

    bool seen_greater_than_or_equal_value = false;

    while (current != flist.end()) {
        if ((*current < value) && seen_greater_than_or_equal_value) {
            flist.push_front(*current);
            flist.erase_after(prev);

            current = prev;
            current++;
        } else {
            if (*current >= value) {
                seen_greater_than_or_equal_value = true;
            }

            prev = current;
            current++;
        }
    }
}

void print_list(const forward_list<int>& flist) {
    for (auto elem : flist) {
        cout << elem << ", ";
    }
    cout << endl;
}

void run_partition(forward_list<int> flist, int value) {
    print_list(flist);
    partition(flist, value);
    print_list(flist);
    cout << endl;
}

int main() {
    run_partition({3, 5, 8, 5, 10, 2, 1}, 5);
    run_partition({3, 5, 8, 5, 10, 2, 1}, 2);
    run_partition({3, 5, 8, 5, 10, 2, 1}, 7);
}

