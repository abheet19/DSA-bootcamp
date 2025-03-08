import { lowerBound } from "./lower-bound.js";

/**
 * @param {number[]} nums  - The rotated sorted array to search in
 * @param {number} target - The target value to find lower bound for
 * @returns {number} - Index of the first element >= target value
 */

class Solution {
  findPivot(nums) {
    let low = 0,
      high = nums.length - 1;
    while (low < high) {
      let mid = low + Math.floor((high - low) / 2);
      if (nums[mid] > nums[high]) {
        low = mid + 1;
      } else {
        high = mid;
      }
    }
    const pivot = low; //or high
    return pivot;
  }
  lowerBoundRotated(nums, target) {
    const pivot = this.findPivot(nums);

    // Decide which segment might contain the lower bound.
    // The array is split into two sorted parts: [pivot, n-1] and [0, pivot-1]
    const n=nums.length
    if (target >= nums[pivot] && target <= nums[n - 1]) {
      return lowerBound(nums, target, pivot, nums.length - 1);
    } else {
      return lowerBound(nums, target, 0, pivot - 1);
    }
  }
}

// Example usage:
const rotatedNums = [4, 5, 6, 1, 2, 3];
const target = 2;

const solution = new Solution();
const index = solution.lowerBoundRotated(rotatedNums, target);
console.log("Lower bound index in rotated array:", index);
