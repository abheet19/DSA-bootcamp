class Solution {
    //Time Complexity O(n)
  singleNonDuplicateBruteForce(nums) {
    const n = nums.length;
    if (n === 1) {
      return nums[0];
    }
    for (let i = 0; i < nums.length; i++) {
      if (i == 0) {
        if (nums[i] !== nums[i + 1]) {
          return nums[i];
        }
      }
      if (i == n - 1) {
        if (nums[i - 1] !== nums[i]) {
          return nums[i];
        }
      } else {
        if (nums[i - 1] != nums[i] && nums[i] != nums[i + 1]) {
          return nums[i];
        }
      }
    }
    return -1;
  }
  //Time Complexity O(n)
  singleNonDuplicateUsingXOR(nums) {
    let ans = 0;

    nums.forEach((element) => {
      ans = ans ^ element;
    });
    return ans;
  }
}

solution = new Solution();
console.log(solution.singleNonDuplicateBruteForce([1, 1, 2, 3, 3, 4, 4, 8, 8])); //2

console.log(solution.singleNonDuplicateUsingXOR([1, 1, 2, 3, 3, 4, 4, 8, 8])); //2
