# You have a rectangular white board with some black cells. The black cells create a connected black 
# figure, i.e. it is possible to get from any black cell to any other one through connected adjacent 
# (sharing a common side) black cells.

# Find the perimeter of the black figure assuming that a single cell has unit length.

# It's guaranteed that there is at least one black cell on the table.

# Example

# For

# matrix = [[false, true,  true ],
#           [true,  true,  false],
#           [true,  false, false]]
# the output should be
# solution(matrix) = 12.

class Solution:
    def polygonPerimeter(self, matrix):
        def perimeter(r,c):
            p = 0
            if r == 0 or not matrix[r-1][c]:
                p += 1
            if r == len(matrix)-1 or not matrix[r+1][c]:
                p += 1
            if c == 0 or not matrix[r][c-1]:
                p += 1
            if c == len(matrix[0])-1 or not matrix[r][c+1]:
                p += 1
            return p
        
        p = 0
        for r in range(len(matrix)):
            for c in range(len(matrix[0])):
                if matrix[r][c]:
                    p += perimeter(r,c)
        return p
    

    
