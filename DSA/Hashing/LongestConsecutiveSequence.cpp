
#include <bits/stdc++.h>
using namespace std;

class Solution
{

public:
    // Function to find the longest consecutive sequence
    // Time Complexity: O(n^2)
    // Space Complexity: O(1)
    int longestConsecutiveBruteForce(vector<int> &nums)
    {
        // If the array is empty
        if (nums.empty())
        {
            return 0;
        }
        int n = nums.size();
        // Initialize the longest sequence length
        int longest = 1;

        // Iterate through each element in the array
        for (int i = 0; i < n; i++)
        {
            // Current element
            int x = nums[i];
            // Count of the current sequence
            int cnt = 1;

            // Search for consecutive numbers
            while (find(nums.begin(), nums.end(), x + 1) != nums.end())
            {
                x += 1;
                cnt += 1;
            }
            // Update the longest sequence length found so far
            longest = max(longest, cnt);
        }
        return longest;
    }

    // Time Complexity: O(n log n) due to sorting
    // Space Complexity: O(1) (Ignoring space used by sorting algorithm)
    int longestConsecutiveBetter(vector<int> &nums)
    {
        if (nums.empty())
        { // Return 0 if array is empty
            return 0;
        }
        int longest = 1;           // Track longest sequence length
        int cnt = 0;               // Count current sequence length
        int lastSmaller = INT_MIN; // Track last smaller element

        sort(nums.begin(), nums.end());

        for (int num : nums)
        {
            if (lastSmaller == num - 1) // If consecutive number exists
            {
                cnt++;             // Increment sequence count
                lastSmaller = num; // Update last smaller element
            }
            else if (lastSmaller != num - 1) // If consecutive number doesn't exits
            {
                cnt = 1;           // Reset count for new sequence
                lastSmaller = num; // Update last smaller element
            }
            longest = max(longest, cnt); // Update longest if needed
        }
        return longest;
    }

    // Time complexity: O(n) because each element is inserted and checked once.
    // Space complexity: O(n) in the worst case due to the hash set.

    int longestConsecutiveOptimal(vector<int> &nums)
    {
        if (nums.empty())
        { // Return 0 if array is empty
            return 0;
        }
        int longest = 1;                                  // Track longest sequence length
        unordered_set<int> set(nums.begin(), nums.end()); // Initialize set with all numbers
        /* Traverse the set to find the longest sequence  */

        for (int num : nums)
        {
            if (set.find(num - 1) == set.end()) // Check if 'num' is a starting number of a sequence
            {
                // Initialize the count of the current sequence
                int cnt = 1;
                // Starting element of the sequence
                int startingElement = num;

                // Find consecutive numbers in the set
                while (set.find(startingElement + 1) != set.end())
                {
                    startingElement += 1; // Move to the next element in the sequence
                    cnt += 1;             // Increment the count of the sequence
                }
                longest = max(longest, cnt); // Update longest if needed
            }
        }
        return longest;
    }
};

int main()
{
    vector<int> a = {100, 4, 200, 1, 3, 2};

    // Create an instance of the Solution class
    Solution solution;

    // Function call for longest consecutive sequence
    int ans = solution.longestConsecutiveBruteForce(a);
    cout << "The longest consecutive sequence for brute force approach is " << ans << "\n";

    ans = solution.longestConsecutiveBetter(a);
    cout << "The longest consecutive sequence for sorting approach is " << ans << "\n";

    ans = solution.longestConsecutiveOptimal(a);
    cout << "The longest consecutive sequence for optimal approach is " << ans << "\n";

    return 0;
}