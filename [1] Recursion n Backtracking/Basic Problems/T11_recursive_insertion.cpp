#include <iostream>
#include <bits/stdc++.h>
using namespace std;


void insertion_sort(vector<int> &arr, int start)
{
    if (start == arr.size())
        return;
    int j = start - 1;
    while (j >= 0 && arr[j] > arr[j + 1])
    {
        swap(arr[j], arr[j + 1]);
        j--;
    }
    insertion_sort(arr, start + 1);
}

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    insertion_sort(arr, 1);
    for (int x : arr)
        cout << x << " ";
    return 0;
}
