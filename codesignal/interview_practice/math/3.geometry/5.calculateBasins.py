# A group of farmers has some elevation data that we are going to use to help them understand how 
# rainfall flows over their farmland. We represent the farmland as a 2D array of altitudes, 
# the grid, and use the following model, based on the fact that water flows downhill:

# If a cell's four neighboring cells all have altitudes not lower that its own, this cell is a 
# sink in which water collects.
# Otherwise, water will flow into the neighboring cell with the lowest altitude. If a cell is 
# not a sink, you can assume it has a unique lowest neighbor and that this neighbor will be lower 
# than the cell.
# Cells that drain into the same sink, directly or indirectly, are part of the same basin.
# Given an n × n grid of elevations, your goal is to partition the map into basins and output 
# the sizes of the basins, in descending order.

class Solution:
    def calculateBasins(grid):
        d, row, col = {}, len(grid), len(grid[0])
        def dfs(x, y, value):
            stack ,keep_track = [ ((x ,y) ,value) ] ,{(x ,y)}
            while stack:
                (x, y), value = stack.pop()
                for i, j in (0, 1), (1, 0), (-1, 0), (0, -1) :
                    if 0 <=x+i <row and 0 <=y+j <col and grid[x+i][y+j] < value :
                            value ,index = grid[x+i][y+j] ,(x+i,y+j)
                if value == grid[x][y]:
                    d[x,y] = d.get((x, y), set()) | keep_track
                else:
                    keep_track.add(index)
                    stack.append((index, value))
        for i in range(row) :
            for j in range(col) :
                dfs(i, j, grid[i][j])
        return sorted([len(value) for value in d.values()],reverse = 1)