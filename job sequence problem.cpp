#include<bits/stdc++.h>  // call the library

using namespace std; // can use the functions defined in the std

struct Job { // job is a structure that contain variables related to each other
    int id; // Job Id
    int deadline ; // deadline of job (the unit of the time the job should finish in or before it)
    int profit; // Profit if job is over before or on deadline
};
class calculations  { //class called calculations have all the function and calculations
public: // function to compare between the profit of 2 jobs and return boolean
    bool static sort_jobs(Job a, Job b) {
        return (a.profit > b.profit);
    }
    //Function to find the maximum profit and the number of jobs done
    pair < int, int > chosen_jobs(Job arr[], int n) {// pair to make the function return 2 integer output
        sort(arr, arr + n, sort_jobs); // sort the array
        int max_deadline = arr[0].deadline ;// initialize the max profit by the first number in the deadline array
        for (int i = 1; i < n; i++) {// check on the max deadline
            max_deadline = max(max_deadline, arr[i].deadline );
        }

        int selected_jobs[max_deadline + 1]; // array based one

        for (int i = 0; i <= max_deadline; i++) // initializethe array by -1 all
            selected_jobs[i] = -1;

        int countJobs = 0, jobProfit = 0; // the needed answer

        for (int i = 0; i < n; i++) {
            for (int j = arr[i].deadline ; j > 0; j--) {
                if (selected_jobs[j] == -1) {// if true increase the job counter 1 and increase the profit
                    selected_jobs[j] = i;
                    countJobs++;
                    jobProfit += arr[i].profit;
                    break;
                }
            }
        }

        return make_pair(countJobs, jobProfit);
    }
};

int main() {
    int n = 4; // size of the array that will hold our data
    Job arr[n] = {{1,4,20},{2,1,10},{3,1,40},{4,1,30}};

    calculations  obj; // make an object from calculations class
    //function call
    pair < int, int >answer = obj.chosen_jobs(arr, n);
    cout <<answer.first << " " <<answer.second << endl; // use to access the returned values from the function and print it with a space between the 2 values

    return 0;
}