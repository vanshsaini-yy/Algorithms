#include <bits/stdc++.h>
using namespace std;


vector<string> digits = {"1", "2", "3", "4", "5", "6", "7", "8", "9"};

void display_grid(vector<vector<string>> &grid)
{
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
            cout << grid[i][j] << " ";
        cout << endl;
    }
}

bool is_valid_move(int i, int j, string move, vector<vector<string>> &grid)
{
    for (int k = 0; k < 9; k++)
    {
        // Check all cells in current row
        if (grid[i][k] == move)
            return false;
        // Check all cells in current column
        if (grid[k][j] == move)
            return false;
        // Check all cells in current 3x3 box
        if (grid[3 * (i / 3) + (k / 3)][3 * (j / 3) + (k % 3)] == move)
            return false;
    }
    return true;
}

bool solve(vector<vector<string>> &grid)
{
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            if (grid[i][j] == ".")
            {
                for (auto d : digits)
                {
                    if (is_valid_move(i, j, d, grid))
                    {
                        // Make the move and recursively solve the rest of the grid
                        grid[i][j] = d;
                        if (solve(grid))
                            return true;
                        grid[i][j] = ".";
                    }
                }
                // If no valid move is possible, backtrack
                return false;
            }
        }
    }
    // If all cells are filled, the Sudoku is solved
    return true;
}

void solve_sudoku(vector<vector<string>> &grid)
{
    if (solve(grid))
        display_grid(grid);
    else
        cout << "NO SOLUTION\n";
}

int main()
{
    vector<vector<string>> grid = {{"5", "3", ".", ".", "7", ".", ".", ".", "."},
                                   {"6", ".", ".", "1", "9", "5", ".", ".", "."},
                                   {".", "9", "8", ".", ".", ".", ".", "6", "."},
                                   {"8", ".", ".", ".", "6", ".", ".", ".", "3"},
                                   {"4", ".", ".", "8", ".", "3", ".", ".", "1"},
                                   {"7", ".", ".", ".", "2", ".", ".", ".", "6"},
                                   {".", "6", ".", ".", ".", ".", "2", "8", "."},
                                   {".", ".", ".", "4", "1", "9", ".", ".", "5"},
                                   {".", ".", ".", ".", "8", ".", ".", "7", "9"}};
    solve_sudoku(grid);
    return 0;
}
