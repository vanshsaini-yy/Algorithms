#include <bits/stdc++.h>
using namespace std;


// Generate r-element subsets of n elements in arr which may contain duplicates
// For example, arr = {1, 1, 2, 2, 3} and r = 3, the combinations are:
// 1 1 2
// 1 1 3
// 1 2 2
// 1 2 3
// 2 2 3
void generate_combination(int idx, vector<int> combination, int r, vector<int> &arr, vector<vector<int>> &combinations)
{
    if (combination.size() == r) {
        combinations.push_back(combination);
        return;
    }

    for (int j = idx; j < arr.size(); j++)
    {
        if (j != idx && arr[j] == arr[j - 1])
            continue;

        combination.push_back(arr[j]);
        generate_combination(j + 1, combination, r, arr, combinations);
        combination.pop_back();
    }
}

int main()
{
    int n, r;
    cin >> n >> r;

    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    sort(arr.begin(), arr.end());

    vector<vector<int>> combinations;
    generate_combination(0, {}, r, arr, combinations);

    for (auto combination : combinations)
    {
        for (auto e : combination)
            cout << e << " ";
        cout << endl;
    }
    return 0;
}
