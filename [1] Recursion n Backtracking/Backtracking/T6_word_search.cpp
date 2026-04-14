#include <bits/stdc++.h>
using namespace std;


vector<int> di = {1, -1, 0, 0};
vector<int> dj = {0, 0, 1, -1};

bool is_valid_move(int i, int j, int idx, string word, vector<vector<char>> &board, vector<vector<bool>> &visited) {
    int m = board.size();
    int n = board[0].size();

    if (i < 0 || i > m - 1 || j < 0 || j > n - 1 || word[idx] != board[i][j] || visited[i][j])
        return false;
    
    return true;
}

bool search(int i, int j, int idx, string word, vector<vector<char>> &board, vector<vector<bool>> &visited) {
    if (idx == word.length())
        return true;
    
    for (int k = 0; k < di.size(); k++) {
        int new_i = i + di[k];
        int new_j = j + dj[k];

        if (is_valid_move(new_i, new_j, idx, word, board, visited)) {
            visited[i][j] = 1;
            if (search(new_i, new_j, idx + 1, word, board, visited))
                return true;
            visited[i][j] = 0;
        }
    }

    return false;
}


// Leetcode: Word Search
bool word_search(vector<vector<char>>& board, string word) {
    int m = board.size();
    int n = board[0].size();
    vector<vector<bool>> visited(m, vector<bool>(n, 0));

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (board[i][j] == word[0]) {
                if (search(i, j, 1, word, board, visited))
                    return true;
            }
        }
    }

    return false;
}
