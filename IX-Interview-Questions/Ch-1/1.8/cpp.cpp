#include <iostream>
#include <vector>


using namespace std;

/*
 * Runs O(r * c)
 *
 */
void expand_zero(vector<vector<int>>& matrix) {
    vector<int> rows_with_zero {};
    vector<int> cols_with_zero {};

    for (int r = 0; r < matrix.size(); r++) {
        for (int c = 0; c < matrix[r].size(); c++) {
            if (matrix[r][c] == 0) {
                rows_with_zero.push_back(r);
                cols_with_zero.push_back(c);
            }
        }
    }

    for (auto r : rows_with_zero) {
        for (int c = 0; c < matrix[r].size(); c++) {
            matrix[r][c] = 0;
        }
    }

    for (auto c : cols_with_zero) {
        for (int r = 0; r < matrix.size(); r++) {
            matrix[r][c] = 0;
        }
    }
}

void print_matrix(const vector<vector<int>>& matrix) {
    for (auto& row : matrix) {
        for (auto col : row) {
            cout << '\t' << col;
        }
        cout << "\n";
    }
    cout << endl;
}

void run_expand_zero(vector<vector<int>> matrix) {
    print_matrix(matrix);
    expand_zero(matrix);
    print_matrix(matrix);
    cout << "--- Done ---\n\n" << endl;
}


int main() {
    run_expand_zero({
            {1, 2, 3},
            {4, 0, 6},
            {7, 8, 9}});

    run_expand_zero({
            {1, 2, 3, 4},
            {5, 6, 7, 8},
            {9, 10, 0, 12},
            {13, 14, 15, 16}});

    run_expand_zero({
            {1, 2, 3, 4, 5},
            {6, 0, 8, 9, 10},
            {11, 12, 13, 14, 15},
            {16, 17, 18, 0, 20},
            {21, 22, 23, 24, 25}});
}

