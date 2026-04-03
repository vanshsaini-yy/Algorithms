#include <bits/stdc++.h>
using namespace std;


void generate_powerset(int idx, vector<int> &subset, vector<int> &arr, vector<vector<int>> &powerset)
{
    if (idx == arr.size())
    {
        powerset.push_back(subset);
        return;
    }
    subset.push_back(arr[idx]);
    generate_powerset(idx + 1, subset, arr, powerset);
    subset.pop_back();
    generate_powerset(idx + 1, subset, arr, powerset);
}

int main()
{
    vector<int> arr = {1, 2, 3};
    vector<int> subset;
    vector<vector<int>> powerset;
    generate_powerset(0, subset, arr, powerset);
    for (auto &s : powerset)
    {
        for (auto &x : s)
            cout << x << " ";
        cout << endl;
    }
    return 0;
}
