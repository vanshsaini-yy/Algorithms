#include <bits/stdc++.h>
using namespace std;


/**
 * Fractional Knapsack:
 * Given n items each with a weight and a value, and a knapsack of total capacity W,
 * maximize the total value packed. Fractions of an item may be taken — taking a fraction
 * f of item i contributes f * value[i] to the total and f * weight[i] to capacity used.
 *
 * Proof: Greedy is optimal by exchange argument — suppose an optimal solution takes less
 *         of item i (higher density) and more of item j (lower density). Swapping that
 *         unit from j to i increases total value without violating capacity, contradicting
 *         optimality. Hence always preferring higher-density items is globally optimal.
 *
 * Variations:
 *     1. 0/1 knapsack — items cannot be split (greedy fails; use bottom-up DP in O(n·W))
 *     2. Bounded knapsack — each item has a maximum count (DP with binary grouping or
 *        monotone deque to reduce to 0/1 knapsack)
 *     3. Multi-dimensional knapsack — items consume weight and volume (2D DP; no greedy)
 *     4. Fractional knapsack with item dependencies — item i requires item j to be taken
 *        first (greedy order breaks; model as DAG DP)
 *     5. Online fractional knapsack — items arrive one at a time with unknown future items
 *        (competitive-ratio algorithms; optimal offline greedy no longer applicable)
 */

int get_max_value(int n, int W, vector<int> weight, vector<int> value) {
    vector<pair<float, int>> value_per_weight(n);
    for (int i = 0; i < n; i++)
        value_per_weight[i] = { (float)value[i] / weight[i], i };

    sort(value_per_weight.begin(), value_per_weight.end(), greater<pair<float, int>>());

    float total_value = 0.0;
    for (int i = 0; i < n; i++) {
        int idx = value_per_weight[i].second;

        if (weight[idx] <= W) {
            total_value += value[idx];
            W -= weight[idx];
        } else {
            total_value += value_per_weight[i].first * W;
            break;
        }
    }
    return total_value;
}

int main() {
    int n, W;
    cin >> n >> W;

    vector<int> weight(n), value(n);

    for (int i = 0; i < n; i++)
        cin >> weight[i];
    for (int i = 0; i < n; i++)
        cin >> value[i];
        
    cout << get_max_value(n, W, weight, value) << endl;
    return 0;
}
