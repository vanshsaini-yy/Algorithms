#include <bits/stdc++.h>
using namespace std;

/**
 * Job Sequencing — Maximize Total Profit:
 * Given n unit-duration jobs each with a profit and a deadline, select and schedule a subset
 * on a single machine (starting at time 0) such that each selected job finishes by its
 * deadline and total profit is maximized. Each job occupies exactly one time slot.
 *
 * Complexity: O(n * max_deadline) time — sorting is O(n log n) but slot scan dominates;
 *             O(max_deadline) space for the timeline array.
 * 
 * Alternatives: Union-Find slot allocation — replace linear scan with DSU find for O(alpha) 
 *               per assignment, improving to O(n log n) total
 *
 * Variations:
 *     1. Variable durations — jobs take duration[i] slots (greedy order breaks; use DP
 *        with binary search for latest compatible predecessor in O(n log n))
 *     2. Jobs with release times — cannot start before release[i] (profit-descending greedy
 *        no longer optimal; model as weighted interval scheduling with DP)
 */

int max_profit_job_scheduling(int n, vector<int> &deadlines, vector<int>&profits) {
    struct Job {
        int profit;
        int deadline;
        int idx;
    };

    vector<Job> jobs;
    for (int i = 0; i < n; i++)
        jobs.push_back({ profits[i], deadlines[i], i });

    sort(jobs.begin(), jobs.end(), [](const Job &job1, const Job &job2) {
        return job1.profit > job2.profit;
    });

    int latest_deadline = *max_element(deadlines.begin(), deadlines.end());
    vector<int> slots((size_t) latest_deadline, -1);

    int max_profit = 0;
    for (auto job: jobs) {
        for (int i = job.deadline - 1; i >= 0; i--) {
            if (slots[i] == -1) {
                slots[i] = job.idx;
                max_profit += job.profit;
                break;
            }
        }
    }
    return max_profit;
}
