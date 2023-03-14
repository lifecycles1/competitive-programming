# Given a rectangular matrix and an integer column, return an array containing the elements of 
# the columnth column of the given matrix (the leftmost column is the 0th one).

class Solution:
    def extractMatrixColumn(self, matrix, column):
        return [matrix[i][column] for i in range(len(matrix))]