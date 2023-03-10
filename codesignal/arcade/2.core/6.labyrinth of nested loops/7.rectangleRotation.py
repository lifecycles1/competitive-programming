# A rectangle with sides equal to even integers a and b is drawn on the Cartesian plane. 
# Its center (the intersection point of its diagonals) coincides with the point (0, 0), but the 
# sides of the rectangle are not parallel to the axes; instead, they are forming 45 degree angles 
# with the axes.

# How many points with integer coordinates are located inside the given rectangle (including on 
# its sides)?

import math

class Solution:
    def rectangleRotation(self, a, b):
      [m, n] = [int(math.floor(x / math.sqrt(2))) for x in (a, b)]
      return m * n + (m + 1) * (n + 1) - (m + n) % 2