# The longest diagonals of a square matrix are defined as follows:

# the first longest diagonal goes from the top left corner to the bottom right one;
# the second longest diagonal goes from the top right corner to the bottom left one.
# Given a square matrix, your task is to swap its longest diagonals by exchanging their elements 
# at the corresponding positions.

class Solution:
    def swapDiagonals(self, matrix):
        n = len(matrix)
        for i in range(n):
            matrix[i][i], matrix[i][n-i-1] = matrix[i][n-i-1], matrix[i][i]
        return matrix