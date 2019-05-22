#include <iostream>
#include <vector>

/*
 * The obvious solution runs in O(d1 * log(d2))
 * Where d2 is the maximum of row and column
 * and d1 is the minium of row and column
 *
 * I feel like there is a more optimal solution
 *
 */

using namespace std;

pair<int, int> find (const vector<vector<int>>& mat, int val) {
    int rows_count = mat.size();
    int cols_count = mat[0].size();

    if (rows_count < cols_count) {
        for (int r = 0; r < rows_count; ++r) {
            int start = 0;
            int end = mat[r].size() - 1;

            while (start <= end) {
                int mid = start + ((end - start) / 2);

                if (val == mat[r][mid]) {
                    return {r, mid};
                } else if (val < mat[r][mid]) {
                    end = mid - 1;
                } else {
                    start = mid + 1;
                }
            }
        }
    } else {
        for (int c = 0; c < cols_count; ++c) {
            int start = 0;
            int end = mat.size();

            while (start <= end) {
                int mid = start + ((end - start) / 2);

                if (val == mat[mid][c]) {
                    return {mid, c};
                } else if (val < mat[mid][c]) {
                    end = mid - 1;
                } else {
                    start = mid + 1;
                }
            }
        }
    }

    cout << "Value not found" << endl;
    throw "Value not found";
}

void run_find(const vector<vector<int>>& mat, int val) {
    auto result = find(mat, val);
    cout << "(" << result.first << ", " << result.second << ")" << endl;
}

int main() {
    run_find({
            {1, 2, 3},
            {2, 4, 6},
            {3, 6, 9},
            }, 3);

    run_find({
            {1, 2, 3, 4, 5},
            {2, 4, 6, 8, 10},
            }, 3);

    run_find({
            {0, 0},
            {1, 2},
            {2, 4},
            {3, 6},
            {4, 8},
            }, 3);

    run_find({
            {0, 0, 0},
            {1, 2, 3},
            {2, 4, 6},
            {3, 6, 9},
            {4, 8, 12},
            }, 3);

    run_find({
            {1, 2,  3,  4,  5},
            {2, 4,  6,  8,  10},
            {3, 6,  9,  12, 15},
            {4, 8,  12, 16, 20},
            {5, 10, 15, 20, 25},
            }, 3);
}

