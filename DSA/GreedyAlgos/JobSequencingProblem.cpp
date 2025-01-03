#include <bits/stdc++.h>
using namespace std;
/*Given an 2D array Jobs of size Nx3, where Jobs[i][0] represents JobID , Jobs[i][1] represents Deadline , Jobs[i][2] represents Profit associated with that job.
 Each Job takes 1 unit of time to complete and only one job can be scheduled at a time.
The profit associated with a job is earned only if it is completed by its deadline. Find the number of jobs and maximum profit.
*/

/*Example 1
Input : Jobs = [ [1, 4, 20] , [2, 1, 10] , [3, 1, 40] , [4, 1, 30] ]

Output : 2 60

Explanation : Job with JobID 3 can be performed at time t=1 giving a profit of 40.

Job with JobID 1 can be performed at time t=2 giving a profit of 20.

No more jobs can be scheduled, So total Profit = 40 + 20 => 60.

Total number of jobs completed are two, JobID 1, JobID 3.

So answer is 2 60.
*/

// Time Complexity: O(NlogN) + O(N^2)  -> can be,improved to O(NlogN) using Disjoint Set Union (not covered here)
// Space Complexity: O(N)
class Solution
{
public:
    vector<int> JobScheduling(vector<vector<int>> &Jobs)
    {
        // Sort jobs based on profit in descending order
        sort(Jobs.begin(), Jobs.end(), [](vector<int> &a, vector<int> &b)
             { return a[2] > b[2]; });

        int n = Jobs.size(); // Total number of jobs
        int max_profit = 0;  // Initialize the total profit earned
        int count = 0;       // Initialize count
        vector<int> result(2, 0);
        vector<int> slot(n, -1); /*Initialize a hash table to store selected jobs. Each element represents a deadline slot, initially unoccupied.*/

        // Iterate over each job
        for (int i = 0; i < n; i++)
        { /*Iterate over each deadline slot starting
          from the job's deadline*/
            for (int j = min(n, Jobs[i][1]) - 1; j >= 0; j--)
            {
                if (slot[j] == -1) //. If the slot is unoccupied, assign the job to the slot
                {
                    slot[j] = i;              // Assign the job to the slot
                    max_profit += Jobs[i][2]; // Update the total profit
                    count++;                  // Increment the count
                    break;                    // Break the loop
                }
            }
        }

        result[0] = max_profit;
        result[1] = count;

        return result;
    }
};

int main()
{
    vector<vector<int>> jobs = {{1, 4, 20}, {2, 1, 10}, {3, 1, 40}, {4, 1, 30}};

    Solution solution;
    vector<int> result = solution.JobScheduling(jobs);

    cout << "Number of Jobs: " << result[1] << endl;
    cout << "Maximum Profit: " << result[0] << endl;

    return 0;
}