#include <bits/stdc++.h>
using namespace std;


/**
 * Fractional Knapsack Problem:
 * Given weights and values of n items, put these items in a knapsack of capacity W to get the maximum total value.
 * In fractional knapsack, we can break items for maximizing value. For e.g., we can take half of an item.
 * Greedy approach:
 *     1. Calculate the value per unit weight for each item.
 *     2. Sort the items in decreasing order of value per unit weight.
 *     3. Take items in this order until the knapsack is full.
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
