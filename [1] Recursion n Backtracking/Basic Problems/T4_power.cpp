#include <iostream>
#include <bits/stdc++.h>
using namespace std;


float pow(float n, int i)
{
    if (n == 0)
    {
        if (i > 0)
            return 0;
        else if (i < 0)
            return numeric_limits<float>::infinity();
        else
            return numeric_limits<float>::quiet_NaN();
    }
    if (i == 0)
        return 1;
    if (i < 0)
        return 1 / pow(n, -i);
    return n * pow(n, i - 1);
}

int main()
{
    float n;
    int i;
    cin >> n >> i;
    cout << pow(n, i);
    return 0;
}
