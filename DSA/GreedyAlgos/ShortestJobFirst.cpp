#include <bits/stdc++.h>
using namespace std;

/*Function to calculate total waiting 
time using Shortest Job First algorithm*/

class Solution { 
  public:
    long long solve(vector<int>& bt) {
        //your code goes here
    }
};
int main() {
    vector<int> jobs = {1, 2, 3, 4};

    cout << "Array Representing Job Durations: ";
    for (int i = 0; i < jobs.size(); i++) {
        cout << jobs[i] << " ";
    }
    cout << endl;

    Solution solution;
    long long ans = solution.solve(jobs);
    cout << "Total waiting time: " << ans << endl;

    return 0;
}