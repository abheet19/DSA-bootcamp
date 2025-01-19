#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // Time Complexity: O(n) - Single pass through the array
    // Space Complexity: O(n) - Extra space for the hash map
    vector<int> twoSumUsingHashmap(vector<int> &nums, int target)
    {
        // Map to store (element, index) pairs
        unordered_map<int, int> mpp;

        // Size of the nums vector
        int n = nums.size();

        for (int i = 0; i < n; i++)
        {
            // Current number in the vector
            int num = nums[i];
            // Number needed to reach the target
            int moreNeeded = target - num;

            // Check if the complement exists in map
            if (mpp.find(moreNeeded) != mpp.end())
            {
                /* Return the indices of the
                two numbers that sum up to target*/
                return {min(mpp[moreNeeded], i), max(mpp[moreNeeded], i)};
            }

            // Store current number and its index in map
            mpp[num] = i;
        }

        // If no such pair found, return {-1, -1}
        return {-1, -1};
    }

    // Two-Pointer Approach
    // Time Complexity: O(n log n) - Sorting the array
    // Space Complexity: O(1) - No extra space needed
    vector<int> twoSumUsingTwoPointers(vector<int> &nums, int target)
    {
        // Create a vector of pairs to store number and its original index
        vector<pair<int, int>> numWithIndex;
        for (int i = 0; i < nums.size(); i++)
        {
            numWithIndex.emplace_back(nums[i], i);
        }

        // Sort the vector based on the numbers
        sort(numWithIndex.begin(), numWithIndex.end());

        int left = 0;
        int right = numWithIndex.size() - 1;

        while (left < right)
        {
            int currentSum = numWithIndex[left].first + numWithIndex[right].first;
            if (currentSum == target)
            {
                return {min(numWithIndex[left].second, numWithIndex[right].second),
                        max(numWithIndex[left].second, numWithIndex[right].second)};
            }
            if (currentSum < target)
            {
                left++;
            }
            else
            {
                right--;
            }
        }

        // If no such pair found, return {-1, -1}
        return {-1, -1};
    }

    // Find All Pairs That Sum to Target
    // Time Complexity: O(n log n) - Sorting the array
    // Space Complexity: O(n) - Extra space for storing pairs
    vector<vector<int>> findAllPairs(vector<int> &nums, int target) {
        vector<vector<int>> result;
        
        // Sort the original array to use two-pointer technique
        sort(nums.begin(), nums.end());
        
        int left = 0;
        int right = nums.size() - 1;
        
        while(left < right) {
            int currentSum = nums[left] + nums[right];
            if(currentSum == target) {
                if(nums[left] == nums[right]) {
                    int count = right - left + 1;
                    int pairCount = count * (count - 1) / 2;
                    for(int i = 0; i < pairCount; ++i) {
                        result.emplace_back(vector<int>{nums[left], nums[right]});
                    }
                    break;
                }
                else {
                    int countLeft = 1;
                    while(left + 1 < right && nums[left] == nums[left + 1]) {
                        countLeft++;
                        left++;
                    }
                    
                    int countRight = 1;
                    while(right - 1 > left && nums[right] == nums[right - 1]) {
                        countRight++;
                        right--;
                    }
                    
                    for(int i = 0; i < countLeft * countRight; ++i) {
                        result.emplace_back(vector<int>{nums[left], nums[right]});
                    }
                    
                    left++;
                    right--;
                }
            }
            else if(currentSum < target) {
                left++;
            }
            else {
                right--;
            }
        }
        
        // Sort the result as per the problem statement
        sort(result.begin(), result.end());
    // Print the resulting pairs
        
        return result;
    }
};

int main()
{
    int n = 5;
    vector<int> nums = {2, 6, 5, 8, 11};
    int target = 14;

    // Create an instance of the Solution class
    Solution sol;

    // Call the twoSum method to find the indices
    vector<int> ans = sol.twoSumUsingHashmap(nums, target);

    // Print the result
    cout << "This is the answer: [" << ans[0] << ", " << ans[1] << "]" << endl;

    return 0;
}
