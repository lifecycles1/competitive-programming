# Imagine a white rectangular grid of n rows and m columns divided into two parts by a 
# diagonal line running from the upper left to the lower right corner. 
# Now let's paint the grid in two colors according to the following rules:

# A cell is painted black if it has at least one point in common with the diagonal;
# Otherwise, a cell is painted white.
# Count the number of cells painted black.

class Solution:
    def countBlackCells(n, m):
        def gcd(a, b):
            while b:
                a, b = b, a % b
            return a
        return n + m + gcd(n, m) - 2