#include <bits/stdc++.h>
using namespace std;


void count_distinct_subsequence(string subsequence, int idx, string s, unordered_set<string> &subsequences)
{
    if (idx == s.length())
    {
        subsequences.insert(subsequence);
        return;
    }
    count_distinct_subsequence(subsequence + s[idx], idx + 1, s, subsequences);
    count_distinct_subsequence(subsequence, idx + 1, s, subsequences);
}

int main()
{
    string s;
    cin >> s;
    unordered_set<string> subsequences;
    count_distinct_subsequence("", 0, s, subsequences);
    cout << subsequences.size();
    return 0;
}
