#include <bits/stdc++.h>
using namespace std;


// Generate all valid bracket sequences of length 2*k
void generate_parenthesis(string s, int open, int close, int k, vector<string> &bracket_sequences)
{
    if (open == k && close == k)
    {
        bracket_sequences.push_back(s);
        return;
    }
    if (open < k)
        generate_parenthesis(s + "(", open + 1, close, k, bracket_sequences);
    if (close < open)
        generate_parenthesis(s + ")", open, close + 1, k, bracket_sequences);
}

int main()
{
    int k;
    cin >> k;
    vector<string> bracket_sequences;
    generate_parenthesis(string(""), 0, 0, k, bracket_sequences);
    for (auto x : bracket_sequences)
        cout << x << endl;
    return 0;
}
