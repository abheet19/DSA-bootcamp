/**
 * @param {number[]} nums - The sorted array to search in
 * @param {number} x - The target value to find lower bound for
 * @returns {number} - Index of the first element >= target value
 */
class Solution {
  static lowerBound(nums, x) {
    let low = 0,
      high = nums.length - 1;
    let ans = nums.length;

    while (low <= high) {
      let mid = low + Math.floor((high - low) / 2);

      if (nums[mid] >= x) {
        ans = mid;
        high = mid - 1;
      } else {
        low = mid + 1;
      }
    }
    return ans;
  }
}

export const lowerBound = (nums, x) => Solution.lowerBound(nums, x);
