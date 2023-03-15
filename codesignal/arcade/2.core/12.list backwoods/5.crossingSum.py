# Given a rectangular matrix and integers a and b, consider the union of the ath row and the bth 
# (both 0-based) column of the matrix (i.e. all cells that belong either to the ath row or to the bth 
# column, or to both). Return sum of all elements of that union.

class Solution:
    def crossingSum(self, matrix, a, b):
        return sum(matrix[a]) + sum([matrix[i][b] for i in range(len(matrix))]) - matrix[a][b]