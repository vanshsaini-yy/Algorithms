#include <bits/stdc++.h>
using namespace std;


/**
 * Activity Selection Problem:
 * Given n jobs each with a start time and an end time, find the maximum number of
 * non-overlapping jobs a single worker can complete. A worker handles one job at a time;
 * a new job may start exactly when the previous one ends (touching intervals are allowed).
 *
 * Alternatives: DP with binary search in O(n log n) — sort by end time, for each job find
 *               the latest compatible predecessor via binary search; correct but adds code
 *               complexity unnecessarily for the unweighted case. Bitmask DP for tiny n.
 *
 * Variations:
 *     1. Maximize jobs with k workers (interval partitioning — greedy with min-heap of
 *        finish times; assign each job to the worker finishing earliest)
 *     2. Minimum workers to complete all jobs without overlap (interval partitioning —
 *        sort by start time, min-heap tracks earliest free worker; answer = heap max size)
 *     3. Mandatory cooldown between consecutive jobs (shift each job's start by cooldown
 *        before comparing against last_end)
 *     4. Weighted variant — maximize total profit (greedy fails; DP with binary search
 *        for latest compatible predecessor in O(n log n))
 */

int activity_selection_problem(vector<pair<int, int>> &jobs) {
    sort(jobs.begin(), jobs.end(), [](const pair<int, int> &a, const pair<int, int> &b) {
        if (a.second == b.second)
            return a.first < b.first;
        return a.second < b.second;
    });

    int count = 0;
    int last_end = INT_MIN;

    for (const auto &job : jobs) {
        if (job.first >= last_end) {
            last_end = job.second;
            count++;
        }
    }

    return count;
}
