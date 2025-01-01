
#include <bits/stdc++.h>
using namespace std;

class Solution
{

public:
    // Function to count the number of subarrays with XOR equal to k

    // Time complexity: O(n^3)
    // Space complexity: O(1)
    int subarraysWithXorK(vector<int> &nums, int k)
    {
        int n = nums.size();
        if (n == 0)
            return 0;

        int result = 0; // Number of subarrays with XOR equal to k

        // starting index
        for (int startIndex = 0; startIndex < n; startIndex++)
        {
            // ending index
            for (int endIndex = startIndex; endIndex < n; endIndex++)
            {
                /* add all the elements of
                   subarray = nums[startIndex...endIndex]  */
                int currentXor = 0;
                for (int i = startIndex; i <= endIndex; i++)
                {
                    currentXor ^= nums[i];
                }

                if (currentXor == k)
                    result++;
            }
        }
        return result;
    }
    // Time complexity: O(n^2)
    // Space complexity: O(1)
    int subarraysWithXorKBetter(vector<int> &nums, int k)
    {
        int n = nums.size();
        if (n == 0)
            return 0;
        int result = 0; // Number of subarrays with XOR equal to k

        // starting index
        for (int startIndex = 0; startIndex < n; startIndex++)
        {
            int currentXor = 0;
            // ending index
            for (int endIndex = startIndex; endIndex < n; endIndex++)
            {

                /* add all the elements of
                   subarray = a[startIndex...endIndex]  */
                currentXor ^= nums[endIndex];

                if (currentXor == k)
                    result++;
            }
        }
        return result;
    }
    /**
     * Finds the Number of subarrays with XOR equal to k
     * It uses a hash table (unordered_map) to achieve O(n) time complexity.
     * Time Complexity: O(n)
     * Space Complexity: O(n)
     *
     * @param nums The input vector containing integers.
     * @param k The target sum.
     * @return Number of subarrays with XOR equal to k
     */

    int subarraysWithXorKOptimal(vector<int> &nums, int k)
    {
        int n = nums.size();
        unordered_map<int, int> prefixXorMap;
        int currentXor = 0, result = 0;

        prefixXorMap[0] = 1; // Initialize the map with 0 XOR
        for (int i = 0; i < n; i++)
        {
            // Add current element to the prefix xor:
            currentXor ^= nums[i];

            /*Calculate the value to
            remove (currentXor ^ k)*/
            int xorToRemove = currentXor ^ k;

            /* Add the number of subarrays
             with the xor to be removed*/
            result += prefixXorMap[xorToRemove];

            /* Update the count of current
            prefix xor in the map*/
            prefixXorMap[currentXor] += 1;
        }
        return result;
    }
};

int main()
{
    Solution solution;
    vector<int> a = {3, 1, 2, 4};
    int k = 6;

    int count = solution.subarraysWithXorK(a, k);
    cout << "The number of subarrays with XOR k for brute force approach is/are: " << count << "\n";

    count = solution.subarraysWithXorKBetter(a, k);
    cout << "The number of subarrays with XOR k for better approach is/are: " << count << "\n";

    count = solution.subarraysWithXorKOptimal(a, k);
    cout << "The number of subarrays with XOR k for optimal approach is/are: " << count << "\n";

    return 0;
}