#include <bits/stdc++.h>
using namespace std;


// Leetcode: Combination Sum I
// Target sum subset with repetition allowed any number of times
void solve(int idx, int rem_sum, vector<int> subset, vector<int> &arr, vector<vector<int>> &subsets)
{
    if (idx == arr.size())
    {
        if (rem_sum == 0)
            subsets.push_back(subset);
        return;
    }

    if (arr[idx] <= rem_sum)
    {
        subset.push_back(arr[idx]);
        solve(idx, rem_sum - arr[idx], subset, arr, subsets); 
        subset.pop_back();
    }

    solve(idx + 1, rem_sum, subset, arr, subsets);
}

vector<vector<int>> combinationSum(vector<int> &arr, int target_sum)
{
    vector<vector<int>> subsets;
    solve(0, target_sum, vector<int>(), arr, subsets);
    return subsets;
}
