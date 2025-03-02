class Solution{
    //Time Complexity O(n^1/2)
    floorSqrt(x){
        if(x == 0 ){
            return 0;
        }
        let ans=1;
        for(let i=0;i*i <=x;i++){
            ans=i;
        }
        return ans;
    }
    floorSqrtOptimal(x){
        if(x == 0){
            return 0;

        }
        let low=0,high=x;
        let ans=1;
        
        while(low<=high){
            let mid= low+ Math.floor((high-low)/2);

            if(mid*mid <=x){
                ans=mid;
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
        return ans;
    }
}
solution= new Solution();
console.log(solution.floorSqrt(25));

console.log(solution.floorSqrtOptimal(25))