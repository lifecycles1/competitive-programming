# You are given an m x n integer array grid. There is a robot initially located at the 
# top-left corner (i.e., grid[0][0]). The robot tries to move to the bottom-right corner 
# (i.e., grid[m - 1][n - 1]). The robot can only move either down or right at any point in time.

# An obstacle and space are marked as 1 or 0 respectively in grid. A path that the robot takes 
# cannot include any square that is an obstacle.

# Return the number of possible unique paths that the robot can take to reach the bottom-right corner.

# The testcases are generated so that the answer will be less than or equal to 2 * pow(10,9).

from typing import List

class Solution:
    def uniquePathsWithObstacles(self, obstacleGrid: List[List[int]]) -> int:
        m = len(obstacleGrid)
        n = len(obstacleGrid[0])
        dp = [[0] * n for _ in range(m)]
        dp[0][0] = 1 - obstacleGrid[0][0]
        for i in range(1, m):
            dp[i][0] = dp[i - 1][0] * (1 - obstacleGrid[i][0])
        for j in range(1, n):
            dp[0][j] = dp[0][j - 1] * (1 - obstacleGrid[0][j])
        for i in range(1, m):
            for j in range(1, n):
                dp[i][j] = (dp[i - 1][j] + dp[i][j - 1]) * (1 - obstacleGrid[i][j])
        return dp[m - 1][n - 1]