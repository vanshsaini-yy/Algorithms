#include <bits/stdc++.h>
using namespace std;


// Count the number of subsets of an array that sum up to a target sum
// Repetition of elements is not allowed
void count_subset_given_sum(int idx, int curr_sum, vector<int> &arr, int target_sum, int &cnt)
{
    if (idx == arr.size())
    {
        if (curr_sum == target_sum)
            cnt++;
        return;
    }
    count_subset_given_sum(idx + 1, curr_sum + arr[idx], arr, target_sum, cnt);
    count_subset_given_sum(idx + 1, curr_sum, arr, target_sum, cnt);
}

int main()
{
    int n, target_sum, cnt = 0;
    cin >> n >> target_sum;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    count_subset_given_sum(0, 0, arr, target_sum, cnt);
    cout << cnt;
    return 0;
}
