# Sudoku is a number-placement puzzle. The objective is to fill a 9 × 9 grid with digits so that 
# each column, each row, and each of the nine 3 × 3 sub-grids that compose the grid contains all of 
# the digits from 1 to 9.

# This algorithm should check if the given grid of numbers represents a correct solution to Sudoku.

# Example

# For
# grid = [[1, 3, 2, 5, 4, 6, 9, 8, 7],
#         [4, 6, 5, 8, 7, 9, 3, 2, 1],
#         [7, 9, 8, 2, 1, 3, 6, 5, 4],
#         [9, 2, 1, 4, 3, 5, 8, 7, 6],
#         [3, 5, 4, 7, 6, 8, 2, 1, 9],
#         [6, 8, 7, 1, 9, 2, 5, 4, 3],
#         [5, 7, 6, 9, 8, 1, 4, 3, 2],
#         [2, 4, 3, 6, 5, 7, 1, 9, 8],
#         [8, 1, 9, 3, 2, 4, 7, 6, 5]]
# the output should be
# solution(grid) = true;

# For
# grid = [[8, 3, 6, 5, 3, 6, 7, 2, 9],
#         [4, 2, 5, 8, 7, 9, 3, 8, 1],
#         [7, 9, 1, 2, 1, 4, 6, 5, 4],
#         [9, 2, 1, 4, 3, 5, 8, 7, 6],
#         [3, 5, 4, 7, 6, 8, 2, 1, 9],
#         [6, 8, 7, 1, 9, 2, 5, 4, 3],
#         [5, 7, 6, 9, 8, 1, 4, 3, 2],
#         [2, 4, 3, 6, 5, 7, 1, 9, 8],
#         [8, 1, 9, 3, 2, 4, 7, 6, 5]]
# the output should be
# solution(grid) = false.

class Solution:
    def sudoku(self, grid):
        # check rows
        for row in grid:
            seen = set()
            for num in row:
                if num in seen:
                    return False
                seen.add(num)
        # check columns
        for i in range(9):
            seen = set()
            for j in range(9):
                if grid[j][i] in seen:
                    return False
                seen.add(grid[j][i])
        # check 3x3 sub-grids
        for i in range(0, 9, 3):
            for j in range(0, 9, 3):
                seen = set()
                for row in range(i, i+3):
                    for col in range(j, j+3):
                        if grid[row][col] in seen:
                            return False
                        seen.add(grid[row][col])
        return True