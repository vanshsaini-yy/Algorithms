#include <bits/stdc++.h>
using namespace std;


/**
 * Coin Change — Greedy (Canonical Denominations):
 * Given a set of coin denominations and a target amount, find the minimum number of coins
 * needed to make exactly that amount. This greedy approach is correct only for canonical
 * denomination systems (e.g. {1,5,10,25} or Euro coins) where each tier divides cleanly
 * into the next; for arbitrary systems use DP instead.
 *
 * Proof: For canonical systems, greedy is optimal by exchange argument — if the optimal
 *         solution uses k coins of denomination d where k·d could be replaced by a single
 *         larger coin, that replacement strictly reduces the count. Iterating largest-first
 *         ensures no such replacement is missed, so the greedy count equals the optimum.
 *
 * Variations:
 *     1. Count all distinct ways to make the amount (unbounded knapsack DP — greedy inapplicable)
 *     2. Minimum coins with limited supply per denomination (bounded knapsack DP or
 *        binary grouping trick to reduce to 0/1 knapsack)
 *     3. Minimum coins for every amount 1..N (precompute full DP table once; O(1) per query)
 *     4. Minimum coins with at most k distinct denominations used (DP with extra dimension k)
 *     5. Fewest coins where order of selection matters (permutation count — exponential;
 *        use memoized recursion)
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
