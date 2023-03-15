# Mark got a rectangular array matrix for his birthday, and now he's thinking about all the fun things 
# he can do with it. He likes shifting a lot, so he decides to shift all of its i-contours in a clockwise 
# direction if i is even, and counterclockwise if i is odd.

# Here is how Mark defines i-contours:

# the 0-contour of a rectangular array as the union of left and right columns as well as top and 
# bottom rows;
# consider the initial matrix without the 0-contour: its 0-contour is the 1-contour of the initial matrix;
# define 2-contour, 3-contour, etc. in the same manner by removing 0-contours from the obtained arrays.
# Implement a function that does exactly what Mark wants to do to his matrix.

# Example

# For

# matrix = [[ 1,  2,  3,  4],
#            [ 5,  6,  7,  8],
#            [ 9, 10, 11, 12],
#            [13, 14, 15, 16],
#            [17, 18, 19, 20]]
# the output should be

# solution(matrix) = [[ 5,  1,  2,  3],
#                      [ 9,  7, 11,  4],
#                      [13,  6, 15,  8],
#                      [17, 10, 14, 12],
#                      [18, 19, 20, 16]]

from collections import OrderedDict
import math

class Solution:
    def contoursShifting(self, matrix):
        layers = math.ceil(min(len(matrix), len(matrix[0])) / 2)
        # layers
        for l in range(layers):
            # directions
            wr, wc = len(matrix[0])-l, len(matrix)-l
            cells = [(l,c) for c in range(l, wr)] + [(r,wr-1) for r in range(l+1,wc)] 
            cells += [(wc-1, c) for c in range(wr-2, l-1, -1)] + [(r, l) for r in range(wc-2, l, -1)]
            stored = None
            cells = list(OrderedDict.fromkeys(cells))
            if l % 2:
                cells = cells[::-1]
            for cell in cells:
                r, c = cell[0], cell[1]
                matrix[r][c], stored = stored, matrix[r][c]
            matrix[cells[0][0]][cells[0][1]] = stored

        return matrix
            
        
    