#include <bits/stdc++.h>
using namespace std;


// Generate all partitions of number n, where order of elements in partition matters.
// For example, for n = 3, the partitions are:
// 1 1 1
// 1 2
// 2 1
// 3
vector<vector<int>> generate_partitions(int n)
{
    if (n == 0)
        return {{}};

    vector<vector<int>> partitions;
    for (int i = 1; i <= n; i++) {
        auto sub_partitions = generate_partitions(n - i);
        for (auto& sub_partition : sub_partitions) {
            sub_partition.push_back(i);
            partitions.push_back(sub_partition);
        }
    }
    return partitions;
}

int main()
{
    int n;
    cin >> n;
    auto partitions = generate_partitions(n);
    for (auto partition : partitions)
    {
        for (auto x : partition)
            cout << x << " ";
        cout << endl;
    }
    return 0;
}
