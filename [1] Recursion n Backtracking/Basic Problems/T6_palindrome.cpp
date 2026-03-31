#include <iostream>
#include <bits/stdc++.h>
using namespace std;


bool is_palindrome(string &s, int l, int r)
{
    if (l > r)
        return true;
    if (s[l] != s[r])
        return false;
    return is_palindrome(s, l + 1, r - 1);
}

int main()
{
    string s;
    cin >> s;
    cout << is_palindrome(s, 0, s.length() - 1);
    return 0;
}
