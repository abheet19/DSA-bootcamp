class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        maximum= float('-inf')
        size=len(nums)

        # for i in range(size):     #o(n^2 approach)
        #     sum=0
        #     for j in range(i,size):
        #         sum += nums[j]
        #         maximum=max(sum,maximum)
        
        # return maximum
        sum=0
        for i in range(size):   #o(n) time
            sum +=nums[i]

            if sum > maximum:
                maximum=sum

            if sum < 0:
                sum=0

        return maximum        
    
    
solution = Solution()
print(solution.maxSubArray([-2,1,-3,4,-1,2,1,-5,4])) #6

        