#include <bits/stdc++.h>
using namespace std;

/*Function to calculate total waiting 
time using Shortest Job First algorithm*/

class Solution { 
  public:
    long long ShortestJobFirst(vector<int>& bt) {
      
      sort(bt.begin(), bt.end());
      long long time=0;
      long long total_wait_time=0;
      for(int burst_time:bt){
        total_wait_time+=time;
        time+=burst_time;

      }
      return total_wait_time/bt.size();
    }
};
int main() {
    vector<int> jobs = {9, 3, 1, 8, 2};

    cout << "Array Representing Job Durations: ";
    for (int i = 0; i < jobs.size(); i++) {
        cout << jobs[i] << " ";
    }
    cout << endl;

    Solution solution;
    long long ans = solution.ShortestJobFirst(jobs);
    cout << "Total waiting time: " << ans << endl;

    return 0;
}