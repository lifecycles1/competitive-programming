# Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right, 
# which minimizes the sum of all numbers along its path.

# Note: You can only move either down or right at any point in time.

from typing import List

class Solution:
    def minPathSum(self, grid: List[List[int]]) -> int:
        m, n = len(grid), len(grid[0])
        prev = [float("inf")] * n
        prev[-1] = 0

        for row in range(m-1, -1, -1):
            dp = [float("inf")] * n
            for col in range(n-1, -1, -1):
                if col < n-1:
                    dp[col] = min(dp[col], dp[col+1])
                dp[col] = min(dp[col], prev[col]) + grid[row][col]
            prev = dp
        
        return prev[0]
    
