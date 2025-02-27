/**
 * @param {number[]} nums
 * @param {number} target
 * @return {boolean}
 */
class Solution {
  searchInARotatedSortedArrayII(nums, target) {
    let low=0,high=nums.length-1;
    while(low<=high){
        let mid=low+Math.floor((high-low)/2);

        if(nums[mid] === target){
            return true;
        }
        if(nums[low] === nums[mid] && nums[mid] === nums[high]){
            low++;
            high--;
            continue;
        }
        //Left Sorted
        if(nums[low] <=nums[mid]){
            if(nums[low]<=target && target<=nums[mid]){
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        //Right Sorted
        else {
            if(target>=nums[mid] && target<=nums[high]){
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
    }
    return false;
  }
}
solution = new Solution();
console.log(
  solution.searchInARotatedSortedArrayII([7, 8, 1, 2, 3, 3, 3, 4, 5, 6], 7)
); //true
