
#include <bits/stdc++.h>
using namespace std;

class Solution
{

public:
    // Function to count the number of subarrays with sum equal to k
    // Time complexity: O(n^3)
    // Space complexity: O(1)
    int subarraySum(vector<int> &nums, int k)
    {
        int n = nums.size();
        if (n == 0)
            return 0;

        int result = 0; // Number of subarrays with sum equal to k

        // starting index
        for (int startIndex = 0; startIndex < n; startIndex++)
        {
            // ending index
            for (int endIndex = startIndex; endIndex < n; endIndex++)
            {
                /* add all the elements of
                   subarray = nums[startIndex...endIndex]  */
                int currentSum = 0;
                for (int i = startIndex; i <= endIndex; i++)
                {
                    currentSum += nums[i];
                }

                if (currentSum == k)
                    result++;
            }
        }
        return result;
    }
    // Time complexity: O(n^2)
    // Space complexity: O(1)
    int subarraySumBetter(vector<int> &nums, int k)
    {
        int n = nums.size();
        if (n == 0)
            return 0;
        int result = 0; // Number of subarrays with sum equal to k

        // starting index
        for (int startIndex = 0; startIndex < n; startIndex++)
        {
            int currentSum = 0;
            // ending index
            for (int endIndex = startIndex; endIndex < n; endIndex++)
            {

                /* add all the elements of
                   subarray = a[startIndex...endIndex]  */
                currentSum += nums[endIndex];

                // When sum is equal to k, check the maxLength
                if (currentSum == k)
                    result++;
            }
        }
        return result;
    }

    /**
     * Finds the Number of subarrays with sum equal to k
     * It uses a hash table (unordered_map) to achieve O(n) time complexity.
     * Time Complexity: O(n)
     * Space Complexity: O(n)
     *
     * @param nums The input vector containing integers.
     * @param k The target sum.
     * @return Number of subarrays with sum equal to k
     */

    int subarraySumOptimal(const vector<int> &nums, int k)
    {
        int n = nums.size();
        unordered_map<int, int> prefixSumMap;
        int currentSum = 0, result = 0;

        // Setting 0 in the map.
        prefixSumMap[0] = 1;
        for (int i = 0; i < n; i++)
        {
            // Add current element to the prefix sum:
            currentSum += nums[i];

            /*Calculate the value to
            remove (currentSum - k)*/
            int sumToRemove = currentSum - k;

            /* Add the number of subarrays
             with the sum to be removed*/
            result += prefixSumMap[sumToRemove];

            /* Update the count of current
            prefix sum in the map*/
            prefixSumMap[currentSum] += 1;
        }
        return result;
    }
};

int main()
{
    Solution solution;
    vector<int> a = {3, 1, 2, 4};
    int k = 6;

    int count = solution.subarraySum(a, k);
    cout << "The no. of subarrays for brute force approach is/are: " << count << "\n";

    count = solution.subarraySumBetter(a, k);
    cout << "The no. of subarrays for better approach is/are: " << count << "\n";

    count = solution.subarraySumOptimal(a, k);
    cout << "The no. of subarrays for optimal approach is/are: " << count << "\n";

    return 0;
}