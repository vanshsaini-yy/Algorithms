#include <bits/stdc++.h>
using namespace std;


// Counts the number of ways to go from top-left to the bottom right corner of a n x m grid
// under the constraint that one can only move right and down
int count_grid_paths(int n, int m)
{
    if(n == 1 or m == 1)
        return 1;
    // Case when you move right from currenct cell, left in a n x (m-1) grid
    int count1 = count_grid_paths(n, m-1);

    // Case when you move down from current cell, left in a (n-1) x m grid
    int count2 = count_grid_paths(n-1, m);

    return count1 + count2;
}

int main()
{
    int n, m;
    cin >> n >> m;
    cout << count_grid_paths(n, m);
    return 0;
}
