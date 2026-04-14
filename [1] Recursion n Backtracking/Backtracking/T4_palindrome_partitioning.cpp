#include <bits/stdc++.h>
using namespace std;


// Leetcode: Palindrome Partitioning I
bool is_palindrome(int i, int j, string s) {
    while(i <= j) {
        if (s[i] != s[j])
            return false;
        i++, j--;
    }
    return true;
}

void solve(int i, vector<string> partition, string s, vector<vector<string>> &partitions) {
    if (i == s.length()) {
        partitions.push_back(partition);
        return;
    }
    for (int j = i; j <= s.length(); j++) {
        if (is_palindrome(i, j, s)) {
            partition.push_back(s.substr(i, j - i + 1));
            solve(j + 1, partition, s, partitions);
            partition.pop_back();
        }
    }
}

vector<vector<string>> partition(string s) {
    vector<vector<string>> partitions;
    solve(0, vector<string>(), s, partitions);
    return partitions;
}
