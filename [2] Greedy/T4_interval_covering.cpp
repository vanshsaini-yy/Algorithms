#include <bits/stdc++.h>
using namespace std;


/**
 * Interval Covering Problem:
 * Given a set of intervals and a target interval, find the minimum number of intervals from the set that can cover the target interval. 
 * If it's not possible to cover the target interval, return -1.
 * 
 * Greedy approach:
 *     1. Sort the intervals based on their starting point (and if tie, by their ending point).
 *     2. Initialize a variable to keep track of the point we are trying to cover (starting from the target's starting point).
 *     3. Iterate through the sorted intervals and for each interval that starts before or at the point we are trying to cover, update the maximum reachable point.
 *     4. If at any point, the maximum reachable point is less than or equal to the point we are trying to cover, it means we cannot cover the target interval, hence return -1.
 *     5. If we successfully cover the target interval, return the count of intervals used.
 * Bonus: Try proving that greedy approach is optimal.
 * Leetcode: Video Stitching (similar)
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
