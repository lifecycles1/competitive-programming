# Given an array of points on a 2D plane, find the maximum number of points that are visible 
# from point (0, 0) with a viewing angle that is equal to 45 degrees.

# The array of points. For each valid i, points[i] contains exactly 2 elements and represents 
# the ith point, where points[i][0] is the x-coordinate and points[i][1] is the y-coordinate. 
# It is guaranteed that there are no points located at (0, 0) and there are no two points located 
# at the same place

import math

class Solution:
    def visiblePoints(points):
        # count the number of points on the origin
        origin = 0
        for point in points:
            if point[0] == 0 and point[1] == 0:
                origin += 1
        # count the number of points on the same line
        # and find the maximum number of points on the same line
        # by rotating the coordinate system
        maxPoints = 0
        for i in range(len(points)):
            points[i] = [points[i][0], points[i][1], math.atan2(points[i][1], points[i][0])]
        points.sort(key = lambda x: x[2])
        for i in range(len(points)):
            points.append([points[i][0], points[i][1], points[i][2] + 2 * math.pi])
        j = 0
        for i in range(len(points)):
            while j < len(points) and points[j][2] - points[i][2] <= math.pi / 4:
                j += 1
            maxPoints = max(maxPoints, j - i)
        return maxPoints + origin