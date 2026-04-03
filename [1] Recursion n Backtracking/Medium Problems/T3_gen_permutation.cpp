#include <bits/stdc++.h>
using namespace std;


void generate_permutation(vector<bool> &used, vector<int> &permutation, int n, vector<vector<int>> &permutations)
{
    if (permutation.size() == n)
    {
        permutations.push_back(permutation);
        return;
    }
    
    for (int i = 1; i <= n; i++)
    {
        if (used[i])
            continue;
        used[i] = true;
        permutation.push_back(i);
        generate_permutation(used, permutation, n, permutations);
        used[i] = false;
        permutation.pop_back();
    }
}

int main()
{
    int n = 3;
    vector<int> permutation;
    vector<bool> used(n + 1, false);
    vector<vector<int>> permutations;

    generate_permutation(used, permutation, n, permutations);
    for (const auto &perm : permutations)
    {
        for (int num : perm)
            cout << num << " ";
        cout << endl;
    }
    return 0;
}
