#include <bits/stdc++.h>
using namespace std;


bool solve(int idx, string s, vector<string> &wordDict) {
    if (idx == s.length())
        return true;

    int n = s.length() - idx;

    for (string word: wordDict) {
        int m = word.length();
        
        if (m > n)
            continue;

        if (word == s.substr(idx, m)) {
            if (solve(idx + m, s, wordDict))
                return true;
        }
    }

    return false; 
}

// Leetcode: Word Break
bool word_break(string s, vector<string>& wordDict) {
    return solve(0, s, wordDict);
}
