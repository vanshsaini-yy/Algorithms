#include <bits/stdc++.h>
using namespace std;


/**
 * Coin Change Problem:
 * Count minimum number of coins required to make a given amount.
 * Greedy approach: Always choose the largest denomination coin available until the amount is reduced to zero.
 * This approach works correctly for Euro denomination coins (1, 2, 5, 10, 20, 50, 100, 200).
 * For other coin systems, this approach may not yield the optimal solution., for e.g., (1, 3, 4).
 * Bonus: Prove that the greedy approach always works for Euro coin denominations.
 */

int count_min_coins(vector<int>& coins, int amt) {
    int cnt = 0;
    int i = 0, n = coins.size();
    sort(coins.begin(), coins.end(), greater<int>());
    while (amt > 0 && i < n) {
        cnt += amt / coins[i];
        amt %= coins[i];
        i++;
    }
    return cnt;
}

int main() {
    vector<int> coins = {1, 2, 5, 10, 20, 50, 100, 200};
    int amt;
    cin >> amt;
    cout << count_min_coins(coins, amt) << endl;
    return 0;
}
