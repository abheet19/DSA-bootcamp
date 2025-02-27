class Solution {
    findMin(nums) {
        let low=0,high=nums.length-1;
    let answer=Infinity;
     while(low<=high){
        let mid=low+Math.floor((high-low) / 2);

        if(nums[low] <= nums[high]){
            answer=Math.min(answer,nums[low]);
        }
        //Check min in left sorted
        if(nums[low]<=nums[mid]){
            answer=Math.min(answer,nums[low]);
            low=mid+1;
        }
        else{
            answer=Math.min(answer,nums[mid]);
            high=mid-1;
        }
       
     }
      return answer;
    }
}


solution = new Solution();
console.log(solution.findMin([3,4,5,1,2])); //1