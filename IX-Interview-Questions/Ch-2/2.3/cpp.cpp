#include <iostream>
#include <forward_list>


using namespace std;

/*
 * Runs O(n)
 *
 * Can't completely solve this problem with forward_lists. The actual list
 * must be passed. This problem could be solved completely by creating
 * a custom singly linked list.
 *
 * EDIT:
 *
 * This is slower than the optimal solution
 *
void delete_node(forward_list<int>::iterator& node, forward_list<int>& flist) {
    forward_list<int>::iterator prev {};
    auto next = node;
    next++;

    while (next != flist.end()) {
        *node = *next;

        prev = node;
        node = next;
        next++;
    }

    flist.erase_after(prev);
}
*/

/*
 * Runs O(1)
 *
 */
void delete_node(forward_list<int>::iterator& node, forward_list<int>& flist) {
    auto prev = node;
    node++;
    *prev = *node;
    flist.erase_after(prev);
}

void print_list(const forward_list<int>& flist) {
    for (auto elem : flist) {
        cout << elem << ", ";
    }
    cout << endl;
}

void run_delete_middle(forward_list<int> flist, int index) {
    print_list(flist);

    auto p = flist.begin();
    while ((p != flist.end()) && (index > 0)) {
        p++;
        index--;
    }

    delete_node(p, flist);

    print_list(flist);
    cout << endl;
}

int main() {
    run_delete_middle({1, 2, 3, 4, 5, 6, 7}, 0);
    run_delete_middle({1, 2, 3, 4, 5, 6, 7}, 2);
    run_delete_middle({1, 2, 3, 4, 5, 6, 7}, 3);
    run_delete_middle({1, 2, 3, 4, 5, 6, 7}, 5);
}

