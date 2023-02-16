# You are given an n x n binary matrix grid where 1 represents land and 0 represents water.

# An island is a 4-directionally connected group of 1's not connected to any other 1's. 
# There are exactly two islands in grid.

# You may change 0's to 1's to connect the two islands to form one island.

# Return the smallest number of 0's you must flip to connect the two islands.

from collections import deque
from typing import List

class Solution:
    def shortestBridge(self, grid: List[List[int]]) -> int:
        N = len(grid)
        direct = [[0, 1], [0, -1], [1, 0], [-1, 0]]

        def invalid(r, c):
            return r < 0 or c < 0 or r == N or c == N
        
        visit = set()
        def dfs(r, c):
            if (invalid(r, c) or not grid[r][c] or (r, c) in visit):
                return
            visit.add((r, c))
            for dr, dc in direct:
                dfs(r + dr, c + dc)
        
        def bfs():
            res, q = 0, deque(visit)
            while q:
                for i in range(len(q)):
                    r, c = q.popleft()
                    for dr, dc in direct:
                        curR, curC = r + dr, c + dc
                        if invalid(curR, curC) or (curR, curC) in visit:
                            continue
                        if grid[curR][curC]:
                            return res
                        q.append([curR, curC])
                        visit.add((curR, curC))
                    res += 1

        for r in range(N):
            for c in range(N):
                if grid[r][c]:
                    dfs(r, c)
                    return bfs()
                

# a bit faster than the previous one
class Solution:
    def shortestBridge(self, A: List[List[int]]) -> int:
        found = False
        stack = []
        n, m = len(A), len(A[0])
        # -----------
        # find the first island
        # -----------
        for i in range(n):
            for j in range(m):
                if A[i][j]:
                    # -----------
                    # using depth first search to find all connected ('1') locations, since we already know there are only two islands. so we only need to find the first one 
                    # -----------
                    self.dfs(A, i, j, n, m, stack)
                    found = True
                    break
            if found:
                break
        steps = 0
        # -----------
        # breadth first search, once we find next '1', that is our final answer 
        # -----------
        dirs = [(0, 1), (0, -1), (1, 0), (-1, 0)]
        while stack:
            size = len(stack)
            level = []
            while(size):
                temp = stack.pop()
                size-=1
                x, y = temp[0], temp[1]
                for dx, dy in dirs:
                    tx = x+dx
                    ty = y+dy
                    if tx<0 or ty<0 or tx>=n or ty>=m or A[tx][ty]==2:
                        continue
                    if A[tx][ty]==1:
                        return steps
                    A[tx][ty]=2
                    level.append((tx, ty))
            steps+=1
            stack = level
        return -1 
                
    def dfs(self, A, row, col, n, m, stack):
        # -----------
        # we only need to find connected '1's. that's why we need A[row][col]==1
        # -----------
        if row<0 or col<0 or row>=n or col>=m or A[row][col]!=1:
            return 
        A[row][col]=2
        # -----------
        # use stack for breath first search
        # -----------
        stack.append((row, col))
        self.dfs(A, row+1, col, n, m, stack)
        self.dfs(A, row-1, col, n, m, stack)
        self.dfs(A, row, col+1, n, m, stack)
        self.dfs(A, row, col-1, n, m, stack)
    
    
            