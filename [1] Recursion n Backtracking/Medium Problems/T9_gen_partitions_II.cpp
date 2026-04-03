#include <bits/stdc++.h>
using namespace std;


// Generate all partitions of number n, where order of elements in partition does NOT matter.
// For example, for n = 3, the partitions are:
// 1 1 1
// 1 2
// 3
void solve(int curr_num, int curr_sum, vector<int> partition, int n, vector<vector<int>> &partitions)
{
    if (curr_sum > n)
        return;
    if (curr_num > n)
        return;
    if (curr_sum == n) {
        partitions.push_back(partition);
        return;
    }
    partition.push_back(curr_num);
    solve(curr_num, curr_sum + curr_num, partition, n, partitions);
    partition.pop_back();
    solve(curr_num + 1, curr_sum, partition, n, partitions);
}

int main()
{
    int n;
    cin >> n;
    vector<vector<int>> partitions;
    solve(1, 0, {}, n, partitions);
    for (auto partition : partitions)
    {
        for (auto x : partition)
            cout << x << " ";
        cout << endl;
    }
    return 0;
}
