#include <bits/stdc++.h>
using namespace std;


// Generate all subsequences of a string s
void generate_subsequence(string subsequence, int idx, string s, vector<string> &subsequences)
{
    if (idx == s.length())
    {
        subsequences.push_back(subsequence);
        return;
    }
    generate_subsequence(subsequence + s[idx], idx + 1, s, subsequences);
    generate_subsequence(subsequence, idx + 1, s, subsequences);
}

int main()
{
    string s;
    cin >> s;
    vector<string> subsequences;
    generate_subsequence("", 0, s, subsequences);
    for (auto x : subsequences)
        cout << x << endl;
    return 0;
}
