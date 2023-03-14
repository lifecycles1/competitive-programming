# The longest diagonals of a square matrix are defined as follows:

# the first longest diagonal goes from the top left corner to the bottom right one;
# the second longest diagonal goes from the top right corner to the bottom left one.
# Given a square matrix, your task is to reverse the order of elements on both of its longest diagonals.

class Solution:
    def reverseOnDiagonals(self, matrix):
        n = len(matrix)
        for i in range(n//2):
            matrix[i][i], matrix[n-i-1][n-i-1] = matrix[n-i-1][n-i-1], matrix[i][i]
            matrix[i][n-i-1], matrix[n-i-1][i] = matrix[n-i-1][i], matrix[i][n-i-1]
        return matrix