# You are given two m x n binary matrices grid1 and grid2 containing only 0's 
# (representing water) and 1's (representing land). An island is a group of 1's connected 
# 4-directionally (horizontal or vertical). Any cells outside of the grid are considered 
# water cells.

# An island in grid2 is considered a sub-island if there is an island in grid1 that contains 
# all the cells that make up this island in grid2.

# Return the number of islands in grid2 that are considered sub-islands.

from typing import List

class Solution:
  def countSubIslands(self, grid1: List[List[int]], grid2: List[List[int]]) -> int:
    m, n = len(grid1), len(grid1[0])
    def dfs(i, j):
      if i < 0 or i >= m or j < 0 or j >= n or grid2[i][j] == 0:
        return True
      grid2[i][j] = 0
      res = grid1[i][j] == 1
      res &= dfs(i+1, j)
      res &= dfs(i-1, j)
      res &= dfs(i, j+1)
      res &= dfs(i, j-1)
      return res
    res = 0
    for i in range(m):
      for j in range(n):
        if grid2[i][j] == 1:
          res += dfs(i, j)
    return res