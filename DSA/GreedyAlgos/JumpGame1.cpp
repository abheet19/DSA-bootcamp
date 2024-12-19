#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool canJump(vector<int> &nums)
    {
        int n = nums.size();
        if (n <= 1)
            return true; // Already at or past the end

        int reachable = 0; // Furthest index reachable so far

        for (int idx = 0; idx < n; ++idx)
        {
            // If current index is beyond what we can reach, it's impossible
            if (idx > reachable)
                return false;

            reachable = max(reachable, idx + nums[idx]);
            if (reachable >= n - 1)
                return true; // Reached or surpassed the end
        }
        return false; // Should not be reachable if the previous return statements are correct.
    }
};

int main()
{
    vector<int> nums = {4, 3, 7, 1, 2};

    cout << "Array representing maximum jump from each index: ";
    for (int i = 0; i < nums.size(); i++)
    {
        cout << nums[i] << " ";
    }
    cout << endl;

    Solution solution;
    bool ans = solution.canJump(nums);

    if (ans)
    {
        cout << "It is possible to reach the last index." << endl;
    }
    else
    {
        cout << "It is not possible to reach the last index." << endl;
    }

    return 0;
}