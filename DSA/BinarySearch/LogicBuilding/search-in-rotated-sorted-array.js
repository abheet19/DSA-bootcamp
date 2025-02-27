/**
 *@param {number[]} nums
 *@param {number} target
 *@return {number}
 */
class Solution {
  search(nums, target) {
    let low = 0;
    let high = nums.length - 1;
    let ans = -1;
    while (low <= high) {
      let mid = low + Math.floor((high - low) / 2);
      if (nums[mid] == target) {
        ans = mid;
        break;
      }
      //Left Sorted
      if (nums[low] <= nums[mid]) {
        if (target >= nums[low] && target <= nums[mid]) {
          high = mid - 1; //eliminate right half
        } else {
          low = mid + 1; //eliminate left half
        }
      }
      //Right Sorted
      else {
        if (target >= nums[mid] && target <= nums[high]) {
          low = mid + 1; //eliminate left half
        } else {
          high = mid - 1; //eliminate right half
        }
      }
    }
    return ans;
  }
}

solution = new Solution();
console.log(solution.search([4, 5, 6, 7, 0, 1, 2], 0)); //4
