#include <iostream>
#include <forward_list>


using namespace std;

struct incorrect_k_value {};

/*
 * Runs O(n)
 *
 */
int kth_to_last(forward_list<int> flist, int k) {
    if (k <= 0) {
        throw incorrect_k_value {};
    }

    auto i = flist.begin();
    int pos = 0;
    while ((i != flist.end()) && (pos < k)) {
        i++;
        pos++;
    }

    if (pos < k) {
        throw incorrect_k_value {};
    }

    auto kth_iterator = flist.begin();
    while (i != flist.end()) {
        i++;
        kth_iterator++;
    }

    return *kth_iterator;
}

void run_kth_to_last(forward_list<int> flist, int k) {
    try {
        int kth = kth_to_last(flist, k);
        cout << "Kth to last element: " << kth << endl;
    } catch(incorrect_k_value) {
        cout << "Invalid k value" << endl;
    }
}

int main() {
    run_kth_to_last({}, 2);
    run_kth_to_last({1, 2, 3, 4, 5, 6, 7}, 0);
    run_kth_to_last({1, 2, 3, 4, 5, 6, 7}, 1);
    run_kth_to_last({1, 2, 3, 4, 5, 6, 7}, 2);
    run_kth_to_last({1, 2, 3, 4, 5, 6, 7}, 7);
    run_kth_to_last({1, 2, 3, 4, 5, 6, 7}, 10);
}

