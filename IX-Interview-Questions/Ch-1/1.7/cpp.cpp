#include <iostream>
#include <vector>


using namespace std;

void rotate_matrix(vector<vector<int>>& matrix) {
    for (int r = 0; r < (matrix.size() / 2); r++) {
        for (int c = r; c < (matrix.size() - r - 1); c++) {
            // Upper left to upper right
            int up_right = matrix[c][matrix.size() - r - 1];
            matrix[c][matrix.size() - r - 1] = matrix[r][c];

            // Upper right to bottom right
            int bot_right
                = matrix[matrix.size() - r - 1][matrix.size() - c - 1];
            matrix[matrix.size() - r - 1][matrix.size() - c - 1] = up_right;

            // Bottom right to bottom left
            int bot_left = matrix[matrix.size() - c - 1][r];
            matrix[matrix.size() - c - 1][r] = bot_right;

            // Bottom left to top left
            matrix[r][c] = bot_left;
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

void run_rotate_matrix(vector<vector<int>> matrix) {
    print_matrix(matrix);
    rotate_matrix(matrix);
    print_matrix(matrix);
    rotate_matrix(matrix);
    print_matrix(matrix);
    rotate_matrix(matrix);
    print_matrix(matrix);
    rotate_matrix(matrix);
    print_matrix(matrix);
    cout << "--- Done ---\n\n" << endl;
}

int main() {
    run_rotate_matrix({
            {1, 2, 3},
            {4, 5, 6},
            {7, 8, 9}});

    run_rotate_matrix({
            {1, 2, 3, 4},
            {5, 6, 7, 8},
            {9, 10, 11, 12},
            {13, 14, 15, 16}});

    run_rotate_matrix({
            {1, 2, 3, 4, 5},
            {6, 7, 8, 9, 10},
            {11, 12, 13, 14, 15},
            {16, 17, 18, 19, 20},
            {21, 22, 23, 24, 25}});
}

