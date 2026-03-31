#include <iostream>
#include <bits/stdc++.h>
using namespace std;


void to_decimal(string &bin, int i, int &decm)
{
    if (i == bin.length())
        return;
    decm = decm * 2 + (bin[i] - '0');
    to_decimal(bin, i + 1, decm);
}

int main()
{
    string bin;
    cin >> bin;
    int decm = 0;
    to_decimal(bin, 0, decm);
    cout << decm;
    return 0;
}
