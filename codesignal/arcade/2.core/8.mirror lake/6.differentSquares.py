# Given a rectangular matrix containing only digits, calculate the number of different 
# 2 × 2 squares in it.

class Solution:
    def differentSquares(self, matrix):
        # Create a set to store the unique squares
        squares = set()
        # Loop through the matrix
        for i in range(len(matrix) - 1):
            for j in range(len(matrix[i]) - 1):
                # Create a square
                square = (matrix[i][j], matrix[i][j + 1], matrix[i + 1][j], matrix[i + 1][j + 1])
                # Add the square to the set
                squares.add(square)
        # Return the length of the set
        return len(squares)