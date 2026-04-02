#include <bits/stdc++.h>
using namespace std;


// generate all binary strings of length k such that no two 1's are adjacent
vector<string> generate_binary(int k)
{
    if (k == 1)
        return {"0"};
    auto temp = generate_binary(k - 1);
    vector<string> ans;
    for (string x : temp)
    {
        if (x.back() == '0')
        {
            ans.push_back(x + '0');
            ans.push_back(x + '1');
        }
        else
            ans.push_back(x + '0');
    }
    return ans;
}

int main()
{
    int k;
    cin >> k;
    auto all_sequences = generate_binary(k);
    for(auto x : all_sequences)
        cout << x << endl;
    return 0;
}
