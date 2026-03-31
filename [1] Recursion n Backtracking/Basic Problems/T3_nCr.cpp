#include <iostream>
#include <bits/stdc++.h>
using namespace std;


int nCr(int n, int r)
{
    if (n < 0 || r < 0 || r > n)
        return 0;
    if (r == 0)
        return 1;
    return (n - r + 1) * nCr(n, r - 1) / r;
}

int main()
{
    int n, r;
    cin >> n >> r;
    cout << nCr(n, r);
    return 0;
}
