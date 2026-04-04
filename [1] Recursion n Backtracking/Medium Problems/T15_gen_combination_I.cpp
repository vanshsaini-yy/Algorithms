#include <bits/stdc++.h>
using namespace std;


// Generates r-element subsets of the set {1, 2, 3, ..., n}, i.e., n distinct elements
void generate_combination(int num, vector<int> combination, int n, int r, vector<vector<int>> &combinations)
{
    if (num == n+1)
    {
        if (combination.size() == r)
            combinations.push_back(combination);
        return;
    }
    
    combination.push_back(num);
    generate_combination(num + 1, combination, n, r, combinations);
    combination.pop_back();
    
    generate_combination(num + 1, combination, n, r, combinations);
}

int main()
{
    int n, r;
    cin >> n >> r;
    vector<vector<int>> combinations;

    generate_combination(1, vector<int>(), n, r, combinations);

    for (auto combination : combinations)
    {

        for (auto e : combination)
            cout << e << " ";
        cout << endl;
    }
    return 0;
}
