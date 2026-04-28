#include <bits/stdc++.h>
using namespace std;

/**
 * Minimum Cost to Merge Lists (Huffman Merging):
 * Given n lists with known sizes, repeatedly merge any two lists into one. The cost of a
 * merge equals the sum of the two list sizes. Find the minimum total cost to reduce all
 * lists to a single list.
 *
 * Variations:
 *     1. Merge k lists at a time — cost = sum of k chosen sizes (generalized k-ary Huffman;
 *        pad with zero-cost dummy lists so total count satisfies (n−1) mod (k−1) == 0)
 *     2. Minimize maximum single-merge cost instead of total cost (binary search on answer
 *        + greedy feasibility check)
 *     3. Lists have fixed merge-order constraints (DAG) — cost depends on topology
 *        (DP on tree/DAG structure instead of greedy)
 *     4. Weighted merge cost: cost = w1*s1 + w2*s2 with varying weights (greedy no longer
 *        applies directly; model as shortest-path or DP)
 */

int min_merge_cost(vector<int> &lists)
{
    priority_queue<long long, vector<long long>, greater<long long>> pq;
    
    for (auto list: lists)
        pq.push(list);
        
    long long min_cost = 0;
    
    while(!pq.empty()) {
        int min1 = pq.top();
        pq.pop();

        if (!pq.empty()) {
            int min2 = pq.top();
            pq.pop();

            min_cost += min1 + min2;

            pq.push(min1 + min2);
        }
    }
    return min_cost;
}
