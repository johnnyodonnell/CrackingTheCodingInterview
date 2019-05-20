#include <iostream>
#include <vector>
#include <queue>


using namespace std;

pair<queue<pair<int, int>>, bool> find_path(
        const vector<vector<char>>& grid,
        int r = 0, int c = 0, queue<pair<int, int>> path = {}) {
    if ((r < grid.size()) && (c < grid[r].size()) && (grid[r][c] == 'o')) {
        path.push({r, c});
    }

    if ((r == (grid.size() - 1)) && (c == (grid[r].size() - 1))) {
        return {path, true};
    }

    if ((r >= grid.size()) || (c >= grid[r].size()) || (grid[r][c] != 'o')) {
        return {path, false};
    }

    auto result = find_path(grid, r + 1, c, path);
    if (result.second) {
        return result;
    } else {
        return find_path(grid, r, c + 1, path);
    }
}

int main() {
    const vector<vector<char>> grid {
        {'o', 'o', 'o', 'o', 'o'},
        {'o', 'o', 'o', 'o', 'o'},
        {'o', 'o', 'o', 'x', 'o'},
        {'o', 'x', 'o', 'o', 'o'},
        {'o', 'x', 'o', 'x', 'o'},
    };

    auto result = find_path(grid);
    cout << "Found path: " << result.second << endl;

    auto path = result.first;
    while (!path.empty()) {
        auto pr = path.front();
        cout << "(" << pr.first << ", " << pr.second << "), ";
        path.pop();
    }
    cout << endl;
}

