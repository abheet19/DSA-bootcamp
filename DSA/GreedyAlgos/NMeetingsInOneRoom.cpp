#include <bits/stdc++.h>
using namespace std;
/*
Given one meeting room and N meetings represented by two arrays, start and end, where start[i] represents the start time of the ith meeting and end[i] represents the end time of the
ith meeting, determine the maximum number of meetings that can be accommodated in the meeting room if only one meeting can be held at a time. */
/*Example 1
Input : Start = [1, 3, 0, 5, 8, 5] , End = [2, 4, 6, 7, 9, 9]

Output : 4

Explanation : The meetings that can be accommodated in meeting room are (1,2) , (3,4) , (5,7) , (8,9).
*/
// Time Complexity: O(NlogN)
// Space Complexity: O(N)
class Solution
{
public:
    int maxMeetings(vector<int> &start, vector<int> &end)
    {
         int n = start.size();
        // Vector to store meetings 
        vector<pair<int, int>> meetings;
        
        // Fill the meetings vector with start and end times
        for (int i = 0; i < n; i++) {
            meetings.push_back({start[i], end[i]});
        }

        // Sort the meetings based on the custom comparator
        sort(meetings.begin(), meetings.end(), [](vector<int> &a, vector<int> &b)
             { return a[1] < b[1]; });

        // The end time of last selected meeting
        int limit = meetings[0].second;
        // Initialize count
        int count = 1; 

        /*Iterate through the meetings 
        to select the maximum number 
        of non-overlapping meetings*/
        for (int i = 1; i < n; i++) {
            /*If the current meeting starts 
            after the last selected meeting ends*/
            if (meetings[i].first > limit) {
                /*Update the limit to the end 
                time of the current meeting*/
                limit = meetings[i].second;
                // Increment count
                count++;
            }
        }

        // Return count
        return count;
    }
};

int main()
{
    Solution obj;
    // Start and end times of the meetings
    vector<int> start = {1, 3, 0, 5, 8, 5};
    vector<int> end = {2, 4, 6, 7, 9, 9};
    // Get the maximum number of meetings that can be held
    int maxMeetings = obj.maxMeetings(start, end);
    // Print the maximum number of meetings
    cout << "Maximum number of meetings: " << maxMeetings << endl;
    return 0;
}
