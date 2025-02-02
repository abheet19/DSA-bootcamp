from typing import List


class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        profit=0
        left=0
        right=1

        while right< len(prices):
            # is profitable?
            if prices[left] < prices[right]:
                profit= max(profit,prices[right]-prices[left])
            else:
                left=right

            right+=1
        
        return profit
    
# Time complexity: O(n)
# Space complexity: O(1)

solution=Solution()
print(solution.maxProfit([7,1,5,3,6,4])) # 5