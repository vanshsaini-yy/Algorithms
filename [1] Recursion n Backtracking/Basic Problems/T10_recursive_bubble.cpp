#include <iostream>
#include <bits/stdc++.h>
using namespace std;


void bubble_sort(vector<int> &arr, int last)
{
    if (last == -1)
        return;
    bool swapped = false;
    for (int j = 0; j <= last; j++)
    {
        if (arr[j] > arr[j + 1])
        {
            swap(arr[j], arr[j + 1]);
            swapped = true;
        }
    }
    if (!swapped)
        return;
    bubble_sort(arr, last - 1);
}

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    bubble_sort(arr, n - 2);
    for (int x : arr)
        cout << x << " ";
    return 0;
}
