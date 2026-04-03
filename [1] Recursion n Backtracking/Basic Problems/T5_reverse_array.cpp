#include <bits/stdc++.h>
using namespace std;


void reverse(vector<int> &arr, int l, int r)
{
    if (l >= r)
        return;
    swap(arr[l], arr[r]);
    reverse(arr, l + 1, r - 1);
}

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int &x : arr)
        cin >> x;
    reverse(arr, 0, n - 1);
    for (int x : arr)
        cout << x << " ";
    return 0;
}
