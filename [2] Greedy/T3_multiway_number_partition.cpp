#include <bits/stdc++.h>
using namespace std;


/**
 * Multiway Number Partitioning:
 * Given a set S of n numbers and a positive integer k, partition S into k subsets such that the subset sums are as nearly equal as possible.
 * The nearly equal condition is defined as minimizing the imbalance, which is the sum of the absolute difference between the average sum and the subset sums.
 * General problem is NP-hard, but we can solve a particular case using greedy approach.
 * 
 * Case: Each subset can have at most 2 elements and 1 <= n <= 2k.
 * Greedy approach:
 *     1. Calculate the average sum of the subsets.
 *     2. Add suitable number of zeros to the set to make its size 2k.
 *     3. Sort the numbers in decreasing order.
 *     4. Pair the largest and smallest numbers to form subsets.
 *     5. Calculate the imbalance.
 * Bonus: Try proving that greedy approach is optimal for this case.
 */

float min_imbalance(int n, int k, vector<int> S)
{
    float avg = accumulate(S.begin(), S.end(), 0) / (float)k;

    for (int i = n; i < 2 * k; i++)
        S.push_back(0);

    sort(S.begin(), S.end(), greater<int>());
    
    float imbalance = 0.0;
    for (int i = 0; i < k; i++) {
        int subset_sum = S[i] + S[2 * k - 1 - i];
        imbalance += abs(avg - subset_sum);
    }
    return imbalance;
}

// Bonus: Recursive solution to general case + symmetry breaking introduction
void solve(int idx, vector<int> &subset_sums, float current_imbalance, vector<int> &S, float avg, float &min_imbalance) {
    // Pruning: If we are already worse than the best, stop
    if (current_imbalance >= min_imbalance)
        return;

    if (idx == S.size()) {
        min_imbalance = current_imbalance;
        return;
    }

     // To avoid trying the same subset sum multiple times
    set<int> tried_sums;

    for (int i = 0; i < subset_sums.size(); i++) {
        // Symmetry breaking: 
        // If we've already tried this non-zero subset sum, skip it
        // If we've already tried this zero subset sum, we can break because all subsequent sums will also be zero
        if (tried_sums.count(subset_sums[i])) {
            if (subset_sums[i] == 0) break;
            continue;
        }
        
        tried_sums.insert(subset_sums[i]);

        float old_diff = abs(avg - subset_sums[i]);
        subset_sums[i] += S[idx];
        float new_diff = abs(avg - subset_sums[i]);

        // Update imbalance on the fly
        solve(idx + 1, subset_sums, current_imbalance - old_diff + new_diff, S, avg, min_imbalance);
        
        subset_sums[i] -= S[idx];
    }
}

float min_imbalance_general(int n, int k, vector<int> S) {
    float avg = accumulate(S.begin(), S.end(), 0) / (float)k;
    vector<int> subset_sums(k, 0);
    float min_imbalance = FLT_MAX;
    solve(0, subset_sums, 0.0, S, avg, min_imbalance);
    return min_imbalance;
}
