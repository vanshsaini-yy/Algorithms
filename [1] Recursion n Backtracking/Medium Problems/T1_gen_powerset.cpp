#include <bits/stdc++.h>
using namespace std;


void generate_subset(int idx, vector<int> &arr, vector<int> &subset, vector<vector<int>> &powerset)
{
    if (idx == arr.size())
    {
        powerset.push_back(subset);
        return;
    }
    subset.push_back(arr[idx]);
    generate_subset(idx + 1, arr, subset, powerset);
    subset.pop_back();
    generate_subset(idx + 1, arr, subset, powerset);
}

int main()
{
    vector<int> arr = {1, 2, 3};
    vector<int> subset;
    vector<vector<int>> powerset;
    generate_subset(0, arr, subset, powerset);
    for (auto &s : powerset)
    {
        for (auto &x : s)
            cout << x << " ";
        cout << endl;
    }
    return 0;
}
