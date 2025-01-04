#include <bits/stdc++.h>
using namespace std;

// Similar question to NMeetingsInOneRoom.cpp
// Time Complexity: O(NlogN)
// Space Complexity: O(1)
class Solution
{
public:
    static bool comp(vector<int> val1, vector<int> val2)
    {
        // Compare the ending times of the intervals
        return val1[1] < val2[1];
    }
    int MinRemovalsForNonOverlapping(vector<vector<int>> &intervals)
    {
        // Sort the intervals based on their ending times
        sort(intervals.begin(), intervals.end(), comp);

        // Get total number of intervals
        int n = intervals.size();

        // Initialize counter
        int cnt = 1;

        // Keep track of the ending time
        int lastEndTime = intervals[0][1];

        // Iterate through all intervals
        for (int i = 1; i < n; i++)
        {
            /* Check if the starting time of the current
            interval is greater than or equal to
            the ending time of the last
            selected interval*/
            if (intervals[i][0] >= lastEndTime)
            {
                // Increment counter
                cnt++;
                // Update the ending time
                lastEndTime = intervals[i][1];
            }
        }
        return n - cnt;
    }
};

int main()
{
    Solution obj;
    vector<vector<int>> intervals = {{0, 5}, {3, 4}, {1, 2}, {5, 9}, {7, 9}};

    for (int i = 0; i < intervals.size(); i++)
    {
        cout << "Interval " << i + 1 << " ";
        cout << "Start: " << intervals[i][0] << " ";
        cout << "End: " << intervals[i][1] << endl;
    }

    int ans = obj.MinRemovalsForNonOverlapping(intervals);
    cout << "Minimum intervals to be removed to make the remaining intervals non-overlapping: " << ans << endl;

    return 0;
}