#include <bits/stdc++.h>
using namespace std;


// does not work on n = 0
string to_binary(int n)
{
    if (n == 0)
        return "";
    return to_binary(n / 2) + (char)(n % 2 + '0');
}

int main()
{
    int decm;
    cin >> decm;
    if (decm == 0)
        cout << "0";
    else
        cout << to_binary(decm);
    return 0;
}
