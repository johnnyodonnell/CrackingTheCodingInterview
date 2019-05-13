#include <iostream>
#include <forward_list>
#include <unordered_set>


using namespace std;

void dedup_no_buffer(forward_list<int>& flist) {
    for (auto elem = flist.begin(); elem != flist.end(); elem++) {
        auto prev_elem = elem;

        auto curr_elem = prev_elem;
        curr_elem++;

        while (curr_elem != flist.end()) {
            if (*curr_elem == *elem) {
                curr_elem = flist.erase_after(prev_elem);
            } else {
                prev_elem = curr_elem;
                curr_elem++;
            }
        }
    }
}

void dedup(forward_list<int>& flist) {
    if (flist.empty()) {
        return;
    }

    unordered_set<int> elem_exists {};

    auto prev_elem = flist.begin();
    elem_exists.insert(*prev_elem);

    auto curr_elem = prev_elem;
    curr_elem++;

    while (curr_elem != flist.end()) {
        if (elem_exists.count(*curr_elem)) {
            curr_elem = flist.erase_after(prev_elem);
        } else {
            elem_exists.insert(*curr_elem);
            prev_elem = curr_elem;
            curr_elem++;
        }
    }
}

void print_list(const forward_list<int>& flist) {
    for (auto elem : flist) {
        cout << elem << ", ";
    }
    cout << endl;
}

void run_dedup(forward_list<int> flist) {
    print_list(flist);
    // dedup(flist);
    dedup_no_buffer(flist);
    print_list(flist);
    cout << endl;
}

int main() {
    run_dedup({});
    run_dedup({1});
    run_dedup({1, 6, 6, 7, 8, 4, 6});
    run_dedup({1, 6, 6, 7, 8, 4, 6, 4, 1, 1, 1, 9});
    run_dedup({1, 1, 6, 6, 7, 8, 4, 6});
}

