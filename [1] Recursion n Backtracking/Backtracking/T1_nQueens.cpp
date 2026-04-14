#include <bits/stdc++.h>
using namespace std;


bool is_valid_position(int r, int c, vector<bool> &column, vector<bool> &diag1, vector<bool> &diag2, int n)
{
    if (column[c] || diag1[r + c] || diag2[r - c + n - 1])
        return false;
    return true;
}

void solve(int r, vector<bool> &column, vector<bool> &diag1, vector<bool> &diag2, int n, int &cnt)
{
    if (r == n) {
        cnt++;
        return;
    }

    for (int c = 0; c < n; c++)
    {
        if (is_valid_position(r, c, column, diag1, diag2, n))
        {
            column[c] = diag1[r + c] = diag2[r - c + n - 1] = true;
            solve(r + 1, column, diag1, diag2, n, cnt);
            column[c] = diag1[r + c] = diag2[r - c + n - 1] = false;
        }
    }
}

// Count the number of ways to place n queens on an n x n chessboard such that no two queens threaten each other.
int solve_n_queens(int n)
{
    // column[c] = true if there is a queen in column c
    // diag1[r + c] = true if there is a queen in the main diagonal containing (r, c)
    // diag2[r - c + n - 1] = true if there is a queen in the anti-diagonal containing (r, c)
    
    vector<bool> column(n, false);
    vector<bool> diag1(2 * n - 1, false), diag2(2 * n - 1, false);

    int cnt = 0;
    solve(0, column, diag1, diag2, n, cnt);
    return cnt;
}

int main()
{
    int n;
    cin >> n;
    
    cout << solve_n_queens(n) << endl;
    return 0;
}
