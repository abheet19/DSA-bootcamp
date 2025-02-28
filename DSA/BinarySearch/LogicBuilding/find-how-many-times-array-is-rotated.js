class Solution {
  findKRotation(nums) {
    let low = 0;
    let high = nums.length - 1;
    let ans = 0;
    let min_element = Infinity;
    while (low <= high) {
      let mid = low + Math.floor((high - low) / 2);

      if (nums[low] <= nums[high]) {
        if (min_element > nums[low]) {
          min_element = nums[low];
          ans = low;
        }
      } //check if pivot is in left half

      if (nums[low] <= nums[mid]) {
        if (min_element > nums[low]) {
          min_element = nums[low];
          ans = low;
        }
        low=mid+1;
      }
      //check if pivot is in right half
      else {
        if (min_element > nums[mid]) {
          min_element = nums[mid];
          ans = mid;
        }
        high=mid-1;
      }
    }
    return ans;
  }
}

solution = new Solution();
console.log(solution.findKRotation([4, 5, 6, 7, 0, 1, 2])); //4
