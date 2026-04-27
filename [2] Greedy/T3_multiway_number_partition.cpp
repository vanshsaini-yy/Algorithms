#include <bits/stdc++.h>
using namespace std;


/**
 * Multiway Number Partitioning (Greedy, At-Most-2 Case):
 * Given a set S of n numbers and a positive integer k, partition S into exactly k subsets
 * to minimize imbalance — defined as the sum of absolute differences between each subset
 * sum and the global average sum. The general problem is NP-hard; this greedy approach is
 * optimal for the restricted case where each subset holds at most 2 elements and n <= 2k.
 *
 * Proof: By exchange argument — suppose an optimal solution pairs large element a with
 *         large element b instead of with small element s. Swapping s in for b moves one
 *         pair closer to the mean and the other further; because the array is symmetric
 *         after sorting, the largest-with-smallest pairing balances all deviations
 *         simultaneously and no swap can reduce total imbalance further.
 *
 * Variations:
 *     1. Exact 2-way partition minimizing |S1 − S2| (subset-sum DP in O(n · total_sum))
 *     2. k-way partition, unrestricted subset sizes (LDM heuristic or ILP for exact answer)
 *     3. Partition into k subsets of equal sum — decision version (backtracking with pruning;
 *        NP-complete in general)
 *     4. Minimize the maximum subset sum instead of imbalance (binary search on answer +
 *        greedy feasibility check in O(n log n))
 *     5. Online variant — numbers arrive one at a time (assign each number to the currently
 *        lightest subset; no global sort available)
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
