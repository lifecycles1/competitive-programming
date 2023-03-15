# Consider a (2k+1) × (2k+1) square subarray of an integer integers matrix. Let's call the union of 
# the square's two longest diagonals, middle column and middle row a star. Given the coordinates of 
# the star's center in the matrix and its width, rotate it 45 · t degrees clockwise preserving 
# position of all matrix elements that do not belong to the star.

class Solution:
    def starRotation(self, matrix, center, width, t):
        [r, c] = center
        offset = [(-1,-1), (-1,0), (-1,1), (0,1), (1,1), (1,0), (1,-1), (0,-1)]
        for d in range(1, width // 2 + 1):
            v = [matrix[r+d*i][c+d*j] for (i,j) in offset]
            v = v[-(t%8):]+v[:-(t%8)]
            for o, (i,j) in enumerate(offset):
                matrix[r+d*i][c+d*j] = v[o]
                  
        return matrix