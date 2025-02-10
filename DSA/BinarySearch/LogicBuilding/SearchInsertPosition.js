/**
 *@param {number[]} nums
 *@param {number} target
 *@return {number}
 */

import { lowerBound } from "../Easy/LowerBound.js";

class Solution {
  searchInsert(nums, target) {
    return lowerBound(nums, target);
  }
}

const nums = [1, 2, 2, 3];
const x = 2;

const sol = new Solution();

const ind = sol.searchInsert(nums, x);

console.log("The index is:", ind);
