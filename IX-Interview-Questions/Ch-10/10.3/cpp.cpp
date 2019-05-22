#include <iostream>
#include <vector>

/*
 * The book has a clever solution to get the runtime to O(log2(n))
 *
 *
 */

using namespace std;

int binary_search(const vector<int> vec, int value, int start, int end) {
    if (start <= end) {
        int mid = start + ((end - start) / 2);
        if (value == vec[mid]) {
            return mid;
        } else if (value < vec[mid]) {
            return binary_search(vec, value, start, mid - 1);
        } else {
            return binary_search(vec, value, mid + 1, end);
        }
    }

    throw "Value not found";
}

/*
 * This runs in O(n), but is still slightly more effecient than
 * doing a straight linear search
 *
 */
int find_in_rotated(const vector<int> vec, int value) {
    int i = 0;
    while (i < vec.size()) {
        if (vec[i] == value) {
            return i;
        }

        if (((i + i) < vec.size()) && (vec[i] > vec[i + 1])) {
            return binary_search(vec, value, i + 1, vec.size() - 1);
        }

        i++;
    }

    throw "Value not found";
}

int main() {
    cout << find_in_rotated(
            {1, 2, 3, 4, 5}, 2) << endl;
    cout << find_in_rotated(
            {5, 1, 2, 3, 4}, 2) << endl;
    cout << find_in_rotated(
            {4, 5, 1, 2, 3}, 2) << endl;
    cout << find_in_rotated(
            {3, 4, 5, 1, 2}, 2) << endl;
    cout << find_in_rotated(
            {2, 3, 4, 5, 1}, 2) << endl;
    cout << find_in_rotated(
            {15, 16, 19, 20, 25, 1, 3, 4, 5, 7, 10, 14}, 5) << endl;
}

