#include <bits/stdc++.h>
using namespace std;

/**
 * Counting Self-Avoiding Hamming Walks in a Square Grid
 * Count the number of paths in an n x n grid, starting from the top-left corner (0, 0) and ending at the bottom-right corner (n-1, n-1).
 * Each path visits every cell of the grid exactly once.
 */

vector<int> dj = {0, -1, 1, 0};
vector<int> di = {1, 0, 0, -1};

bool is_inside_grid(int i, int j, int n) {
    return i >= 0 && i < n && j >= 0 && j < n;
}


// Vanilla backtracking solution
void solve_naive(int i, int j, int visited_count, int n, vector<vector<bool>>& visited, long long &cnt) {
    if (i == n - 1 && j == n - 1 && visited_count == n * n) {
        cnt++;
        return;
    }

    for (int k = 0; k < 4; k++) {
        int new_i = i + di[k];
        int new_j = j + dj[k];

        if (is_inside_grid(new_i, new_j, n) && !visited[new_i][new_j]) {
            visited[new_i][new_j] = true;
            solve_naive(new_i, new_j, visited_count + 1, n, visited, cnt);
            visited[new_i][new_j] = false;
        }
    }
}

long long count_spanning_paths_naive(int n) {
    vector<vector<bool>> visited(n, vector<bool>(n, false));
    long long cnt = 0;
    visited[0][0] = true;
    solve_naive(0, 0, 1, n, visited, cnt);
    return cnt;
}

// Bonus: Pruning the search tree
void solve_pruned(int i, int j, int visited_count, int n, vector<vector<bool>>& visited, long long &cnt) {
    if (i == n && j == n && visited_count == n * n) {
        cnt++;
        return;
    }

    // Optimization: If we reach the destination cell before visiting all cells, we can return early
    if (i == n && j == n) {
        return;
    }

    // Optimization: If the path cannot continue forward but can turn either left or right, the grid splits into two parts that both contain unvisited squares, we can return early
    if (!(visited[i][j + 1] ^ visited[i][j - 1]) && !(visited[i + 1][j] ^ visited[i - 1][j])) {
        return;
    }

    for (int k = 0; k < 4; k++) {
        int new_i = i + di[k];
        int new_j = j + dj[k];

        if (!visited[new_i][new_j]) {
            visited[new_i][new_j] = true;
            solve_pruned(new_i, new_j, visited_count + 1, n, visited, cnt);
            visited[new_i][new_j] = false;
        }
    }
}

long long count_spanning_paths_pruned(int n) {
    vector<vector<bool>> visited(n + 2, vector<bool>(n + 2, false));

    // Optimization: Mark the borders as visited to avoid out-of-bounds checks
    for (int k = 0; k < n + 2; k++) {
        visited[k][0] = true;
        visited[0][k] = true;
        visited[k][n + 1] = true;
        visited[n + 1][k] = true;
    }

    long long cnt = 0;
    visited[1][1] = true;

    // Optimization: We can start from (1, 2) instead of (1, 1) to reduce the search space by half, since the path is symmetric
    visited[1][2] = true;
    solve_pruned(1, 2, 2, n, visited, cnt);

    // Multiply by two to account for the symmetric paths that start with (1, 1) -> (2, 1)
    return 2 * cnt;
}

int main() {
    int n;
    cin >> n;
    cout << count_spanning_paths_pruned(n) << endl;
    return 0;
}

// Bonus: Prove that the count of such paths must be zero for even n.
// Study recursion trees and computation of time and space complexity for recurvise solutions.
