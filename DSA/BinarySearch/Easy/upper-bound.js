/**
 * @param {number[]} nums - The sorted array to search in
 * @param {number} x - The target value to find upper bound for
 * @returns {number} - Index of the first element > target value
 */
class Solution {
    static upperBound(nums, x,low,high) {
      const epsilon = 1e-9; // tolerance for floating point comparison
      let ans = nums.length;
  
      while (low <= high) {
        let mid = low + Math.floor((high - low) / 2);
  
        if (nums[mid] - x > epsilon) {
          ans = mid;
          high = mid - 1;
        } else {
          low = mid + 1;
        }
      }
      return ans;
    }
  }
  
  // Sample array and target
  const nums = [1, 2, 2, 3];
  const x = 2;
  
  // Since upperBound is a static method, call it directly on the class
  const ind = Solution.upperBound(nums, x,0,nums.length-1);
  
  console.log("The upper bound is the index:", ind);
  
  export const upperBound = (nums, x) => Solution.upperBound(nums, x);
  