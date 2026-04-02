#include <bits/stdc++.h>
using namespace std;


// `used` array can be avoided in this code at the cost of time complexity. 
// we can check if the current number is already present in the permutation vector or not.
void generate_permutation(vector<bool> &used, vector<int> &permutation, int n, vector<vector<int>> &permutations)
{
    if (permutation.size() == n)
    {
        permutations.push_back(permutation);
        return;
    }
    
    for (int i = 0; i < n; i++)
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
    vector<bool> used(n, false);
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
