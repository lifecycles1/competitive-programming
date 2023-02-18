# Given a 2D grid of size m x n and an integer k. You need to shift the grid k times.

# In one shift operation:

# Element at grid[i][j] moves to grid[i][j + 1].
# Element at grid[i][n - 1] moves to grid[i + 1][0].
# Element at grid[m - 1][n - 1] moves to grid[0][0].
# Return the 2D grid after applying shift operation k times.

from typing import List

class Solution:
    def shiftGrid(self, grid: List[List[int]], k: int) -> List[List[int]]:
        m, n = len(grid), len(grid[0])
        k = k % (m * n)
        if k == 0: return grid

        ans = [[0] * n for _ in range(m)]
        for i in range(m):
            for j in range(n):
                idx = (i * n + j + k) % (m * n)
                ans[idx // n][idx % n] = grid[i][j]
        
        return ans