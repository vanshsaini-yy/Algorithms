#include <bits/stdc++.h>
using namespace std;


/**
 * Job Scheduling — Minimize Total Slack:
 * Given n jobs each with a duration and a deadline, schedule all jobs on a single machine
 * starting at time 0 to minimize the sum of slack[i] = max(0, finish_time[i] - deadline[i])
 * over all jobs.
 *
 * Variations:
 *     1. Minimize maximum slack — worst single job's slack (sort by deadline, not duration;
 *        EDF rule is optimal)
 *     2. Weighted slack — maximize sum of weight[i] * slack[i] (sort by duration/weight
 *        ratio ascending — weighted SPT rule)
 *     3. Jobs with release times — each job cannot start before release[i] (SPT no longer
 *        optimal; use DP for exact solution)
 */

int minimize_slack(vector<int>& deadline, vector<int>& duration) {
    int n = deadline.size();

    struct Job {
        int deadline;
        int duration;
    };

    vector<Job> jobs(n);
    for (int i = 0; i < n; i++) {
        jobs[i] = {deadline[i], duration[i]};
    }

    sort(jobs.begin(), jobs.end(), [](const Job &j1, const Job &j2) {
        return j1.duration < j2.duration;
    });

    int min_slack = 0, job_finish_time = 0;
    for (const auto &job : jobs) {
        job_finish_time += job.duration;
        min_slack += max(0, job_finish_time - job.deadline);
    }

    return min_slack;
}
