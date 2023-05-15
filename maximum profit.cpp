#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


struct Job {
    int start, end, profit;
};

// Comparison between the ends of the jobs we have
bool toSortJobs(const Job& a, const Job& b) {
    return a.end < b.end;
}

// A function to find the maximum profit subset of the non overlapped jobs
int MaxProfit(vector<Job>& jobs) {
    // Sort the jobs in ascending order of their end times
    sort(jobs.begin(), jobs.end(), toSortJobs);

    // Array that has the number of jobs we have
    int n = jobs.size();
    vector<int> maximum(n, 0);

    // set the maximum profit as the profit pf the first job as intial value
    maximum[0] = jobs[0].profit;

    // starting from the second job to the last
    for (int i = 1; i < n; i++) {
        int p = jobs[i].profit;
        int ov = -1;

        // see if the job ends before the start of job i
        for (int j = i - 1; j >= 0; j--) {
            // Find the last job that is not overlapped with job i
            if (jobs[j].end <= jobs[i].start) {
                ov = j;
                break;
            }
        }

        // If there is a non overlapped job, add its profit to the profit of job i
        if (ov != -1) {
            p += maximum[ov];
        }

        // set the maximum[i] as the maximum of the new profit and maximum[i-1]
        maximum[i] = max(maximum[i - 1], p);
    }

    // return maximum[n-1] that represent the final maximum profit
    return maximum[n - 1];
}


int main() {
    //  a vector of four jobs as a test
    vector<Job> jobs = {{1, 6, 6}, {2, 5, 5}, {5, 7, 5}, {6, 8, 3}};


    int maxProfit = MaxProfit(jobs);


    cout << "Maximum profit: " << maxProfit << endl;

    return 0;
}