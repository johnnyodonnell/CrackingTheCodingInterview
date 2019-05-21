#include <iostream>
#include <vector>
#include <unordered_set>


using namespace std;

struct TakenSpaces {
    unordered_set<int> rows {};
    unordered_set<int> cols {};
    unordered_set<int> diags {};
};

void try_queen_on_row(vector<vector<char>> board, TakenSpaces taken, int r) {
    if (r >= board.size()) {
        cout << "  0 1 2 3 4 5 6 7" << endl;
        for (int r = 0; r < board.size(); ++r) {
            cout << r << " ";
            for (int c = 0; c < board[r].size(); ++c) {
                cout << board[r][c] << " ";
            }
            cout << endl;
        }
        cout << endl;
    } else {
        taken.rows.insert(r);
        for (int c = 0; c < 8; ++c) {
            if ((taken.cols.count(c) <= 0)
                    && (taken.diags.count(r - c) <= 0)
                    && (taken.diags.count(r + c) <= 0)) {
                auto board_copy = board;
                board_copy[r][c] = 'Q';

                auto taken_copy = taken;
                taken_copy.cols.insert(c);
                taken_copy.diags.insert(r + c);
                taken_copy.diags.insert(r - c);

                try_queen_on_row(board_copy, taken_copy, r + 1);
            }
        }
    }
}

void print_queens() {
    vector<vector<char>> board {};
    for (int r = 0; r < 8; ++r) {
        board.push_back({});
        for (int c = 0; c < 8; ++c) {
            board[r].push_back('-');
        }
    }

    try_queen_on_row(board, {}, 0);
}

int main() {
    print_queens();
}

