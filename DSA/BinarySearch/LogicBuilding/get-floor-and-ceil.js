class Solution {
  /**
   * @param {number[]} nums - The sorted array to search in
   * @param {number} x - The target value to find floor and ceil for
   * @returns {number[]} - The floor and ceil values of the target
   * */
  //Time Complexity: O(log n)
  //Space Complexity: O(1)
  getFloorAndCeil(nums, x) {
    let floor = this.getFloor(nums, x);
    let ceil = this.getCeil(nums, x);
    return [floor, ceil];
  }
  getCeil(nums, x) {
    let low = 0,
      high = nums.length - 1;
    let ans = -1;
    while (low <= high) {
      let mid = low + Math.floor((high - low) / 2);

      if (nums[mid] >= x) {
        ans = nums[mid];
        high = mid - 1;
      } else low = mid + 1;
    }
    return ans;
  }

  getFloor(nums, x) {
    let low = 0,
      high = nums.length - 1;
    let ans = -1;
    while (low <= high) {
      let mid = low + Math.floor((high - low) / 2);

      if (nums[mid] <= x) {
        ans = nums[mid];
        low = mid + 1;
      } else high = mid - 1;
    }
    return ans;
  }
}

let nums = [3, 4, 4, 7, 8, 10];
let x = 5;

// Create an instance of the Solution class
let sol = new Solution();

// Function call to get floor and ceil
let result = sol.getFloorAndCeil(nums, x);

console.log("The floor and ceil are:", result[0], result[1]);
