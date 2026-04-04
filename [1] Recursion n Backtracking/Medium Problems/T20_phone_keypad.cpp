#include <bits/stdc++.h>
using namespace std;


// Leetcode: 17. Letter Combinations of a Phone Number
void generate_codes(int idx, string code, vector<int> &arr, vector<string> &mapping, vector<string> &codes)
{
    if (idx == arr.size())
    {
        codes.push_back(code);
        return;
    }

    for (char ch : mapping[arr[idx]])
    {
        code += ch;
        generate_codes(idx + 1, code, arr, mapping, codes);
        code = code.substr(0, code.size() - 1);
    }
}

int main()
{
    vector<string> mapping = {"0", "1", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

    int n;
    cin >> n;
    vector<int> arr(n);

    for (int i = 0; i < n; i++)
        cin >> arr[i];

    vector<string> codes;
    generate_codes(0, "", arr, mapping, codes);

    for (string code : codes)
        cout << code << " ";
    return 0;
}
