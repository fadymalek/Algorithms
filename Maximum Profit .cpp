#include <algorithm>
#include <iostream>
using namespace std;

// A job has start time, end time and profit.
struct Job {
    int start, end, profit;
};

// sorting the jobs according to end time

bool toSortJobs(Job j1, Job j2)
{
    return (j1.end < j2.end);
}

//finding whether the jobs are overlapped or not
//-1 means overlapping
int nonOverlapped(Job arr[], int i)
{
    for (int j = i - 1; j >= 0; j--) {
        if (arr[j].end <= arr[i].start)
        return j;
    }
    return -1;
}

/// a function returns the maximum possible profit
int maxProfit(Job arr[], int n)
{
    // Sort jobs according to end time
    sort(arr, arr + n, toSortJobs);


    // an array to store the profit
    int* prof = new int[n];
    prof[0] = arr[0].profit;


    for (int i = 1; i < n; i++) {
        // Find profit when there is non overlapped jobs
        int inProf = arr[i].profit;
        int l = nonOverlapped(arr, i);
        if (l != -1)
            inProf += prof[l];

        prof[i] = max(inProf, prof[i - 1]);
    }

    // store the result the maximum profit
    int result = prof[n - 1];
    delete[] prof;

    return result;
}

// Driver program
int main()
{
    Job arr[] = { {1, 6, 6}, {2, 5, 5}, {5, 7, 5}, {6, 8, 3} };
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "The maximum profit is "
         << maxProfit(arr, n);
    return 0;
}