# In the popular Minesweeper game you have a board with some mines and those cells that don't contain 
# a mine have a number in it that indicates the total number of mines in the neighboring cells. 
# Starting off with some arrangement of mines we want to create a Minesweeper game setup.

# Example

# For

# matrix = [[true, false, false],
#           [false, true, false],
#           [false, false, false]]
# the output should be

# solution(matrix) = [[1, 2, 1],
#                     [2, 1, 1],
#                     [1, 1, 1]]

class Solution:
    def minesweeper(self, matrix):
        # create a new matrix of the same size as the input matrix
        new_matrix = [[0 for j in range(len(matrix[0]))] for i in range(len(matrix))]
        # iterate over the input matrix
        for i in range(len(matrix)):
            for j in range(len(matrix[0])):
                # if the current cell contains a mine, add 1 to all the neighboring cells
                if matrix[i][j]:
                    # top left
                    if i > 0 and j > 0:
                        new_matrix[i-1][j-1] += 1
                    # top
                    if i > 0:
                        new_matrix[i-1][j] += 1
                    # top right
                    if i > 0 and j < len(matrix[0]) - 1:
                        new_matrix[i-1][j+1] += 1
                    # left
                    if j > 0:
                        new_matrix[i][j-1] += 1
                    # right
                    if j < len(matrix[0]) - 1:
                        new_matrix[i][j+1] += 1
                    # bottom left
                    if i < len(matrix) - 1 and j > 0:
                        new_matrix[i+1][j-1] += 1
                    # bottom
                    if i < len(matrix) - 1:
                        new_matrix[i+1][j] += 1
                    # bottom right
                    if i < len(matrix) - 1 and j < len(matrix[0]) - 1:
                        new_matrix[i+1][j+1] += 1
        return new_matrix