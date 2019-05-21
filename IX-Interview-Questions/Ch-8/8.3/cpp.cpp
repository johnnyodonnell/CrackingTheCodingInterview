#include <iostream>
#include <vector>

/*
 * I feel like I missed the reason why this was in the Recursion chapter
 *
 * After looking at the solutions, the reason this is in the Recursion
 * chapter is because binary search actually provides the most efficient
 * solution to this problem
 *
 */

using namespace std;

int magic_index(const vector<int>& vec, bool distinct = true) {
    int i = 0;

    while (i < vec.size()) {
        if (vec[i] == i) {
            return i;
        }

        if (vec[i] < i) {
            i++;
        } else if (distinct) {
            throw "Magic index not found";
        } else {
            i += (vec[i] - i);
        }
    }

    throw "Magic index not found";
}

int main() {
    for (auto& pr : vector<pair<vector<int>, bool>> {
            {{0}, true},
            {{1, 2, 3, 4, 5}, true},
            {{-10, -5, 1, 3, 4, 5}, true},
            {{5, 5, 5, 5, 5, 5}, false},
            {{5, 5, 5, 5}, false},
            }) {
        try {
            cout << magic_index(pr.first, pr.second) << endl;
        } catch(const char *const str) {
            cout << "Exception: " << str << endl;
        }
    }
}

