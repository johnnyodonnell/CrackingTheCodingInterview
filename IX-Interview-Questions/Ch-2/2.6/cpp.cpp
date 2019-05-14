#include <iostream>
#include <forward_list>
#include <vector>


using namespace std;

/*
 * Runs O(n)
 *
 * Could save on space, but runtime would be longer
 *
 */
bool is_palindrome(const forward_list<int>& flist) {
    vector<int> vec {};

    for (auto& value : flist) {
        vec.push_back(value);
    }

    for (int i = 0; i < (vec.size() / 2); i++) {
        if (vec[i] != vec[vec.size() - i - 1]) {
            return false;
        }
    }

    return true;
}

void print_list(const forward_list<int>& flist) {
    for (auto elem : flist) {
        cout << elem << ", ";
    }
    cout << endl;
}

void run_is_palindrome(forward_list<int> flist) {
    print_list(flist);
    cout << "Is palindrome? " << is_palindrome(flist) << endl;
    cout << endl;
}

int main() {
    run_is_palindrome({1, 2, 3, 2, 1});
    run_is_palindrome({1, 2, 2, 1});
    run_is_palindrome({1, 2, 1});
    run_is_palindrome({1, 2, 3, 1});
    run_is_palindrome({1, 2, 3, 2});
    run_is_palindrome({1, 2, 2, 3, 2, 2, 1});
    run_is_palindrome({1, 2, 2, 3, 3, 2, 2, 1});
    run_is_palindrome({1, 2, 2, 2, 2, 1});
    run_is_palindrome({1, 2, 3, 1, 2, 3});
}

