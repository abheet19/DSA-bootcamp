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
  //[1 1 2 2 3 3 4 5 5 6 6]
  // 0 1 2 3 4 5 6 7 8 9 10
  singleNonDuplicateOptimal(nums) {
    const n = nums.length ;

    if (n === 1) {
      return nums[0];
    }
    if (nums[0] !== nums[1]) {
      return nums[0];
    }
    if (nums[n - 1] !== nums[n - 2]) {
      return nums[n - 1];
    }
    let low = 1;
    let high = n - 2;
    while (low <= high) {
      let mid = low + Math.floor((high - low) / 2);

      if (nums[mid] !== nums[mid - 1] && nums[mid] !== nums[mid + 1]) {
        return nums[mid];
      }
      if (
        (mid % 2 === 1 && nums[mid] === nums[mid - 1]) || //We are standing on odd index check prev element , if same eliminate left half
        (mid % 2 === 0 && nums[mid] === nums[mid + 1]) //or standing on even index , check next element , if same eliminate left half
      ) {
        low = mid + 1;
      } else {
        high = mid - 1;
      }
    }
    return -1;
  }
}

solution = new Solution();
console.log(solution.singleNonDuplicateBruteForce([1, 1, 2, 3, 3, 4, 4, 8, 8])); //2

console.log(solution.singleNonDuplicateUsingXOR([1, 1, 2, 3, 3, 4, 4, 8, 8])); //2

console.log(solution.singleNonDuplicateOptimal([1, 1, 2, 3, 3, 4, 4, 8, 8])); //2
