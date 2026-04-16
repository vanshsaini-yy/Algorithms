#include <bits/stdc++.h>
using namespace std;

/**
 * Classic backtracking problem: Knight's Tour
 * Given an n x n chessboard, find a sequence of moves for a knight such that it visits every square exactly once.
 */

vector<int> di = {2, 2, -2, -2, 1, 1, -1, -1};
vector<int> dj = {1, -1, 1, -1, 2, -2, 2, -2};

// Vanilla backtracking solution
bool solve_naive(int i, int j, int num_visited, int n, vector<vector<int>> &moves) {
    if (num_visited == n * n) {
        return true;
    }

    for (int k = 0; k < di.size(); k++) {
        int new_i = i + di[k];
        int new_j = j + dj[k];

        if (new_i < 0 || new_i > n - 1 || new_j < 0 || new_j > n - 1 || moves[new_i][new_j] != -1)
            continue;

        moves[new_i][new_j] = num_visited;

        if (solve_naive(new_i, new_j, num_visited + 1, n, moves))
            return true;

        moves[new_i][new_j] = -1;
    }

    return false;
}

// Warnsdorff's heuristic: Always move to the square with the fewest onward moves
int count_onward_moves(int i, int j, int n, vector<vector<int>> &moves) {
    int count = 0;
    for (int k = 0; k < di.size(); k++) {
        int new_i = i + di[k];
        int new_j = j + dj[k];

        if (new_i < 0 || new_i > n - 1 || new_j < 0 || new_j > n - 1 || moves[new_i][new_j] != -1)
            continue;

        count++;
    }

    return count;
}

bool solve_heuristic(int i, int j, int num_visited, int n, vector<vector<int>> &moves) {
    if (num_visited == n * n) {
        return true;
    }

    vector<pair<int, pair<int, int>>> next_moves;
    for (int k = 0; k < di.size(); k++) {
        int new_i = i + di[k];
        int new_j = j + dj[k];

        if (new_i < 0 || new_i > n - 1 || new_j < 0 || new_j > n - 1 || moves[new_i][new_j] != -1)
            continue;

        int onward_moves = count_onward_moves(new_i, new_j, n, moves);
        next_moves.push_back({onward_moves, {new_i, new_j}});
    }

    sort(
        next_moves.begin(),
        next_moves.end(), 
        [](const pair<int, pair<int, int>> &a, const pair<int, pair<int, int>> &b) {
            return a.first < b.first;
        }
    );

    for (auto &move : next_moves) {
        int new_i = move.second.first;
        int new_j = move.second.second;

        moves[new_i][new_j] = num_visited;

        if (solve_heuristic(new_i, new_j, num_visited + 1, n, moves))
            return true;

        moves[new_i][new_j] = -1;
    }

    return false;
}

vector<vector<int>> knights_tour(int n) {
    vector<vector<int>> moves(n, vector<int>(n, -1));
    moves[0][0] = 0;
    bool exists = solve_naive(0, 0, 1, n, moves);

    if (!exists)
        return {};
    return moves;
}

int main() { 
    int n;
    cin >> n;

    vector<vector<int>> moves = knights_tour(n);

    if (moves.empty()) {
        cout << "No solution exists" << endl;
    } else {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cout << moves[i][j] << " ";
            }
            cout << endl;
        }
    }
    return 0;
}
