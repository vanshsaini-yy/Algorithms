#include <bits/stdc++.h>
using namespace std;


/**
 * Interval Covering Problem:
 * Given a target interval [a, b] and a set of intervals, find the minimum number of
 * intervals needed to completely cover [a, b] with no gaps. An interval [s, e] covers
 * all points x where s <= x <= e. Return -1 if complete coverage is impossible.
 *
 * Proof: Greedy stays ahead — at each step, extending coverage as far as possible is
 *         optimal. Suppose an optimal solution picks interval X instead of the greedy
 *         choice G where end(G) >= end(X). Swapping X for G covers at least as much,
 *         so the remaining suffix is no harder. By induction, the greedy count never
 *         exceeds the optimal count.
 *
 * Alternatives: DP in O(n²) — for each point, try all intervals that start at or before
 *               it; correct but rarely needed. Binary lifting (sparse table) reduces each
 *               greedy jump to O(log n), giving O(n log n) total for very large inputs.
 *
 * Variations:
 *     1. Circular interval covering — target wraps around (double the interval list and
 *        apply linear greedy over the doubled range)
 *     2. Weighted covering — minimize total weight instead of count (greedy fails; model
 *        as shortest-path or DP over sorted endpoints)
 *     3. Cover with at most k intervals — check feasibility via binary search on greedy
 *     4. 2D rectangle covering — cover a rectangle with smaller rectangles (NP-hard in
 *        general; use ILP or heuristic search)
 *     5. Online covering — intervals arrive one at a time with unknown future intervals
 *        (competitive-ratio algorithms; optimal offline greedy no longer applicable)
 */

bool compare(pair<int, int> p1, pair<int, int> p2) {
    if (p1.first != p2.first)
        return p1.first < p2.first;
    else
        return p1.second < p2.second;
}

int min_intervals_to_cover(int n, vector<pair<int, int>> intervals, pair<int, int> target) {
    sort(intervals.begin(), intervals.end(), compare);

    int interval_count = 0;
    int trying_to_cover = target.first;

    for (int i = 0; i < n;) {
        int max_reached = INT_MIN;
        while (i < n && intervals[i].first <= trying_to_cover) {
            max_reached = max(max_reached, intervals[i].second);
            i++;
        }

        if (max_reached >= trying_to_cover) {
            trying_to_cover = max_reached + 1;
            interval_count++;

            if (trying_to_cover > target.second)
                return interval_count;
        }
        else
            return -1;
    }
    return -1;
}
