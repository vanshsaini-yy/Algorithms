#include <bits/stdc++.h>
using namespace std;


vector<string> dir = {"D", "L", "R", "U"};
vector<int> dj = {0, -1, 1, 0};
vector<int> di = {1, 0, 0, -1};

/**
 * Check if (i, j) is a valid position to move to (within the bounds of the grid, not visited before, not a blocked cell)
 */
bool is_valid_move(int i, int j, vector<vector<int>> &grid, vector<vector<bool>> &visited) {
    int n = grid.size();
    if (i < 0 || i > n - 1 || j < 0 || j > n - 1 || visited[i][j] || !grid[i][j])
        return false;
    return true;
}

/**
 * Print all paths from the top-left corner to the bottom-right corner of a grid, where you can only move down, left, right, or up.
 * You cannot move through blocked cells (represented by 0 in the grid). 
 * You cannot visit the same cell more than once in a single path.
 * The path should be represented as a string of characters where 'D' = down, 'L' = left, 'R' = right, and 'U' = up.
 */
void solve(int i, int j, string path, vector<vector<int>> &grid, vector<vector<bool>> &visited, vector<string> &paths) {
    if (i == grid.size() - 1 && j == grid.size() - 1) {
        paths.push_back(path);
        return;
    }

    for (int k = 0; k < 4; k++) {

        int new_i = i + di[k], new_j = j + dj[k];

        if (is_valid_move(new_i, new_j, grid, visited)) {
            path = path + dir[k];
            visited[i][j] = true;
            solve(new_i, new_j, path, grid, visited, paths);
            path = path.substr(0, path.length() - 1);
            visited[i][j] = false;
        }
    }
}

void print_all_paths(vector<vector<int>> &grid) {
    vector<string> paths;
    vector<vector<bool>> visited(grid.size(), vector<bool>(grid.size(), false));

    solve(0, 0, string(), grid, visited, paths);

    for (string path : paths)
        cout << path << endl;
}

int main() {
    int n;
    cin >> n;

    vector<vector<int>> grid(n, vector<int>(n));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> grid[i][j];

    assert(grid[0][0] == 1);

    print_all_paths(grid);
    return 0;
}
