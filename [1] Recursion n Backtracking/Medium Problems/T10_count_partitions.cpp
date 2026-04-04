#include <bits/stdc++.h>
using namespace std;


// Counts the number of ways to partition n ball into any number of boxes such that each box contains at most m balls
// Can even be solved using target sum subset, target = n, set = {1, 2, 3, ..., m}, repetition allowed (T9_gen_partitions_II.cpp)
int count_partition(int n, int m)
{
    if (n == 0)
        return 1;
    if (m == 0 || n < 0)
        return 0;
    // Case when no box is allowed to contain exactly m balls
    auto count1 = count_partition(n, m - 1);
    // Case when some box has been filled with exactly m balls
    auto count2 = count_partition(n - m, m);
    return count1 + count2;
}

int main()
{
    int n, m;
    cin >> n >> m;
    cout << count_partition(n, m);
    return 0;
}
