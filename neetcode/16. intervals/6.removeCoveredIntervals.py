# Given an array intervals where intervals[i] = [li, ri] represent the interval [li, ri), 
# remove all intervals that are covered by another interval in the list.

# The interval [a, b) is covered by the interval [c, d) if and only if c <= a and b <= d.

# Return the number of remaining intervals.

from typing import List

class Solution:
    def removeCoveredIntervals(self, intervals: List[List[int]]) -> int:
        res = right = 0
        intervals.sort(key=lambda a: (a[0], -a[1]))
        for i, j in intervals:
            res += j > right
            right = max(right, j)
        return res