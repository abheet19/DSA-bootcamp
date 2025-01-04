#include <bits/stdc++.h>
using namespace std;
/*Given a 2D array Intervals, where Intervals[i] = [start[i], end[i]] represents the start and end of the ith interval,
the array represents non-overlapping intervals sorted in ascending order by start[i]. 

Given another array newInterval, where newInterval = [start, end] represents the start and end of another interval,
insert newInterval into Intervals such that Intervals remain non-overlapping and sorted in ascending order by start[i].

Return Intervals after the insertion of newInterval.*/

/*Example:

Input : Intervals = [ [1, 3] , [6, 9] ] , newInterval = [2, 5]
Output : [ [1, 5] , [6, 9] ]

Explanation : After inserting the newInterval the Intervals array becomes [ [1, 3] , [2, 5] , [6, 9] ].

So to make them non overlapping we can merge the intervals [1, 3] and [2, 5].
So the Intervals array is [ [1, 5] , [6, 9] ].
*/

// Time Complexity: O(N)
// Space Complexity: O(N)
class Solution {
public:
    vector<vector<int>> insertNewInterval(vector<vector<int>>& intervals, vector<int>& newInterval){
        // Initialize a vector for storing result
        vector<vector<int>> res; 
        
        /* Track the index while iterating through intervals */
        int i = 0; 
        
        // Get total intervals
        int n = intervals.size(); 
        
        // Insert intervals before newInterval
        while(i < n && intervals[i][1] < newInterval[0]){
            /* Add intervals to the result vector until their end time is before the start time of newInterval */
            
            res.push_back(intervals[i]); 
            // Move to next interval
            i = i + 1; 
        }
        
        // Merge overlapping intervals
        while(i < n && intervals[i][0] <= newInterval[1]){

            /* Update the start time of newInterval to the minimum of its current start time and the start time of the current interval */
            newInterval[0] = min(newInterval[0], intervals[i][0]); 
            
            /* Update the end time of newInterval to the maximum of its current end time and the end time of the current interval */
            newInterval[1] = max(newInterval[1], intervals[i][1]); 
            
            // Move to the next interval
            i = i + 1; 
        }
        
        /* Add the merged interval to the result vector */
        res.push_back(newInterval); 
        
        /* Insert remaining intervals after newInterval */
        while(i < n){
            
            /* Add the remaining intervals after newInterval to the result vector */
            res.push_back(intervals[i]); 
            
            // Move to next interval
            i = i + 1; 
        }
        
        // Return result vector
        return res; 

    }
};

int main() {
    vector<vector<int>> intervals = {{1, 2}, {3, 4}, {6, 7}, {8, 10}, {12, 16}};
    cout << "Intervals Array: ";
    for(auto interval: intervals){
        cout << "[" << interval[0] << ", "<< interval[1]<< "], ";
    }
    cout << endl;
    
    vector<int> newInterval = {5, 8};
    cout << "New Interval to be Inserted: ";
    cout << "[" << newInterval[0] << ", "<< newInterval[1]<< "]" << endl;
    
    Solution sol;
    vector<vector<int>> result = sol.insertNewInterval(intervals, newInterval);
    for(auto interval: result){
        cout << "[" << interval[0] << ", "<< interval[1]<< "], ";
    }
    cout << endl;
    
    return 0;
}


