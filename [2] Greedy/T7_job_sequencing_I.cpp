#include <bits/stdc++.h>
using namespace std;


/**
 * Job Sequencing — Maximize Count:
 * Given n jobs each with a duration and a deadline, find the maximum number of jobs that
 * can be completed on a single machine starting at time 0. Each job must finish on or
 * before its deadline, jobs cannot overlap, and job i takes exactly duration[i] time units.
 *
 * Variations:
 *     1. Maximize total profit instead of count (greedy fails; DP with binary search for
 *        latest compatible predecessor in O(n log n))
 *     2. Jobs with release times — each job cannot start before release[i] (earliest
 *        deadline first no longer optimal; use DP or preemptive EDF scheduling)
 *     3. Multiple machines — schedule on k parallel machines (reduce to k independent
 *        single-machine problems with a min-heap tracking earliest free machine)
 */

vector<int> job_scheduling(vector<int> &duration, vector<int> &deadline) {
    int n = duration.size();

    struct Job {
        int deadline;
        int duration;
        int index;
    };

    vector<Job> jobs(n);
    for (int i = 0; i < n; i++) {
        jobs[i] = {deadline[i], duration[i], i};
    }

    sort(jobs.begin(), jobs.end(), [](const Job &j1, const Job &j2) {
        if (j1.deadline != j2.deadline)
            return j1.deadline < j2.deadline;
        return j1.duration < j2.duration;
    });

    vector<int> scheduled_jobs;
    int last_end = 0;

    for (const auto &job : jobs) {
        if (last_end + job.duration <= job.deadline) {
            scheduled_jobs.push_back(job.index);
            last_end += job.duration;
        }
    }

    return scheduled_jobs;
}
