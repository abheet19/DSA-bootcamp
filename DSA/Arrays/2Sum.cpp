#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
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
    vector<pair<int, int>> findAllPairs(vector<int> &nums, int target)
    {
        vector<pair<int, int>> result;

        // Sort the array to apply two-pointer technique
        sort(nums.begin(), nums.end());

        int left = 0;
        int right = nums.size() - 1;

        while (left < right)
        {
            int currentSum = nums[left] + nums[right];
            if (currentSum == target)
            {
                result.emplace_back(make_pair(nums[left], nums[right]));

                // Move left pointer to the next different number
                while (left < right && nums[left] == nums[left + 1])
                    left++;
                // Move right pointer to the previous different number
                while (left < right && nums[right] == nums[right - 1])
                    right--;

                left++;
                right--;
            }
            else if (currentSum < target)
            {
                left++;
            }
            else
            {
                right--;
            }
        }

        return result;
    }
};

/*
    Time Complexity: O(N)
    Space Complexity: O(N)

    Where 'N' is the total number of elements in the array.
*/
#include <unordered_map>

vector<pair<int, int>> twoSum(vector<int> &arr, int target, int n)
{
    unordered_map<int, int> hashMap;
    vector<pair<int, int>> ans;

    for (int i = 0; i < n; i++)
    {
        int complement = target - arr[i];

        // Check if the complement exists and has not been used up
        if (hashMap.find(complement) != hashMap.end() && hashMap[complement] > 0)
        {
            ans.emplace_back(make_pair(complement, arr[i]));
            hashMap[complement]--;
        }
        else
        {
            hashMap[arr[i]]++;
        }
    }

    // If no valid pair exists.
    if (ans.empty())
    {
        ans.emplace_back(make_pair(-1, -1));
    }

    return ans;
}

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        int N, target;
        cin >> N >> target;
        vector<int> nums(N);
        for (int &num : nums)
            cin >> num;

        Solution sol;
        // Replace findAllPairs with twoSum
        vector<pair<int, int>> ans = twoSum(nums, target, N);

        if (ans.empty())
        {
            cout << "-1 -1\n";
        }
        else
        {
            for (auto &pair : ans)
            {
                cout << pair.first << " " << pair.second << "\n";
            }
        }
    }
    return 0;
}
