#include <bits/stdc++.h>
using namespace std;


// Leetcode: Combination Sum II
// Target sum subset with repetition allowed as many times as the frequency of the number in the input array
void solve(int idx, int rem_sum, int cnt, vector<int> subset, vector<int> &arr, map<int, int> &freq,vector<vector<int>> &subsets)
{
    if (idx == arr.size())
    {
        if (rem_sum == 0)
            subsets.push_back(subset);
        return;
    }

    if (arr[idx] <= rem_sum && cnt < freq[arr[idx]])
    {
        subset.push_back(arr[idx]);
        solve(idx, rem_sum - arr[idx], cnt + 1, subset, arr, freq, subsets); 
        subset.pop_back();
    }

    solve(idx + 1, rem_sum, 0, subset, arr, freq, subsets);
}

vector<vector<int>> combinationSum(vector<int> &arr, int target_sum)
{
    map<int, int> freq;
    for (int num : arr) {
        freq[num]++;
    }
    vector<int> unique_nums;
    for (auto entry : freq) {
        unique_nums.push_back(entry.first);
    }
    vector<vector<int>> subsets;
    solve(0, target_sum, 0, vector<int>(), unique_nums, freq, subsets);
    return subsets;
}

// Combination Sum III: Target sum subset with repetition not allowed and set fixed {1, 2, 3, ..., 9} and subset size fixed at k
// Combination Sum IV:  Target sum subset with repetition allowed and order of elements in subset matters (DP problem)
