import { lowerBound } from "../Easy/LowerBound.js";
import { upperBound } from "../Easy/UpperBound.js";
class Solution {
    /**
     * @param {number[]} nums
     * @param {number} target
     * @return {number[]}
     */
    //Time Complexity: O(n)
    //Space Complexity: O(1)
    searchRangeBrute(nums, target) {
        const result = [];
        let firstOccurence = -1,lastOccurence = -1;
    
        for (let i = 0; i < nums.length; i++) {
            if(nums[i] == target){
                if(firstOccurence == -1){
                    firstOccurence = i;
                }
                lastOccurence = i;
            }
        }

        result.push(firstOccurence);
        result.push(lastOccurence);
        return result;
    }
    //Time Complexity: O(log n)
    //Space Complexity: O(1)
    searchRangeBetter(nums, target) {
        const result = [-1, -1];

        let lb = lowerBound(nums, target);
        let ub = upperBound(nums, target);

        if (lb === nums.length || nums[lb] !== target) { // if target is not present in the array
            return result;
        }
        result[0] = lb;
        result[1] = ub - 1;
        return result;
    }
    searchRangeOptimal(nums, target) {
        const result = [-1, -1];


        return result;
    }
}

const arr= [5,7,7,8,8,10]
const target=8

const solution=new Solution()

let output= solution.searchRangeBrute(arr,target)
console.log(output) // [3,4]

output= solution.searchRangeBetter(arr,target)
console.log(output) // [3,4]
