#include <bits/stdc++.h>
using namespace std;

class Solution
{

public:
    // This solution is for the case when the array contains only positive integers
    // Time complexity: O(n^3)
    // Space complexity: O(1)
    int longestSubarrayWithSumKBruteFoce(vector<int> &nums, int k)
    {
        int n = nums.size();
        if (n == 0)
            return 0;
        int maxLength = 0;

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
                    maxLength = max(maxLength, endIndex - startIndex + 1);
            }
        }
        return maxLength;
    }

    // This solution is for the case when the array contains only positive integers
    // Time complexity: O(n^2)
    // Space complexity: O(1)
    int longestSubarrayWithSumKBetter(vector<int> &nums, int k)
    {
        int n = nums.size();
        if (n == 0)
            return 0;
        int maxLength = 0;

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
                    maxLength = max(maxLength, endIndex - startIndex + 1);
            }
        }
        return maxLength;
    }
    // This solution is for the case when the array contains both positive and negative integers
    // Time complexity: O(nlogn)
    // Space complexity: O(n)
    int longestSubarrayWithSumKOptimal(vector<int> &nums, int k)
    {
        int n = nums.size();
        if (n == 0)
            return 0;

        map<int, int> preSumMap;
        int sum = 0;
        int maxLen = 0;
        for (int i = 0; i < n; i++)
        {
            // calculate the prefix sum till index i
            sum += nums[i];

            // if the sum equals k, update maxLen
            if (sum == k)
            {
                maxLen = max(maxLen, i + 1);
            }

            // calculate the sum of remaining part i.e., sum - k
            int rem = sum - k;

            // calculate the length and update maxLen
            if (preSumMap.find(rem) != preSumMap.end())
            {
                int len = i - preSumMap[rem];
                maxLen = max(maxLen, len);
            }

            // update the map if sum is not already present
            if (preSumMap.find(sum) == preSumMap.end())
            {
                preSumMap[sum] = i;
            }
        }

        return maxLen;
    }

    /**
     * Finds the length of the longest subarray with sum equal to k.
     *
     * This function handles both positive and negative integers efficiently.
     * It uses a hash table (unordered_map) to achieve O(n) time complexity.
     *
     * Time Complexity: O(n)
     * Space Complexity: O(n)
     *
     * @param nums The input vector containing integers.
     * @param k The target sum.
     * @return The length of the longest subarray with sum equal to k.
     */
    int longestSubarrayWithSumKBest(const vector<int> &nums, int k)
    {
        int n = nums.size();
        if (n == 0)
            return 0;

        unordered_map<long long, int> prefixSumMap;
        long long currentSum = 0;
        int maxLength = 0;

        // Initialize the map with 0 sum at index -1
        prefixSumMap[0] = -1;

        // Iterate through the input vector
        for (int i = 0; i < n; ++i)
        {
            currentSum += static_cast<long long>(nums[i]);

            // Check if sum minus k has been seen before
            auto it = prefixSumMap.find(currentSum - k);
            if (it != prefixSumMap.end())
            {
                maxLength = max(maxLength, i - it->second);
            }

            // Update prefix sum map if current sum is not present
            if (prefixSumMap.find(currentSum) == prefixSumMap.end())
            {
                prefixSumMap[currentSum] = i;
            }
        }
        // Removed the special case handling for k == 0
        // if (k == 0)
        // {
        //     maxLength = n;
        // }

        return maxLength;
    }

    /**
     * Checks if there exists at least one subarray with sum equal to k.
     *
     * This function uses a hash map to store prefix sums and determines
     * the existence of a valid subarray in O(n) time complexity.
     *
     * Time Complexity: O(n)
     * Space Complexity: O(n)
     *
     * @param nums The input vector containing integers.
     * @param k The target sum.
     * @return True if such a subarray exists, otherwise false.
     */
    bool hasSubarrayWithSumK(const vector<int> &nums, int k)
    {
        unordered_map<long long, int> prefixSumMap;
        long long currentSum = 0;

        // Initialize the map with 0 sum having been seen once
        prefixSumMap[0] = 1; // Changed from -1 to 1

        for (int num : nums)
        {
            currentSum += static_cast<long long>(num);

            // Check if there is a prefix sum that equals currentSum - k
            if (prefixSumMap.find(currentSum - k) != prefixSumMap.end())
            {
                return true;
            }

            // Update the prefix sum map
            prefixSumMap[currentSum]++;
        }

        return false;
    }
};

int main()
{
    vector<int> a = {1, 3, 4, -8, 0};
    int k = 0;

    // Create an instance of the Solution class
    Solution solution;

    // Function call to get the result
    int len = solution.longestSubarrayWithSumKBruteFoce(a, k);
    cout << "The length of the longest subarray for brute force approach is: " << len << "\n";

    len = solution.longestSubarrayWithSumKBetter(a, k);
    cout << "The length of the longest subarray for better approach is: " << len << "\n";

    len = solution.longestSubarrayWithSumKOptimal(a, k);
    cout << "The length of the longest subarray for optimal approach is: " << len << "\n";

    len = solution.longestSubarrayWithSumKBest(a, k);
    cout << "The length of the longest subarray for best approach is: " << len << "\n";

    // Adding a call to hasSubarrayWithSumK to test its functionality
    bool exists = solution.hasSubarrayWithSumK(a, k);
    cout << (exists ? "true" : "false") << "\n";

    return 0;
}