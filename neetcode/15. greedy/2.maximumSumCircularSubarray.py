# Given a circular integer array nums of length n, return the maximum possible sum of a 
# non-empty subarray of nums.

# A circular array means the end of the array connects to the beginning of the array. 
# Formally, the next element of nums[i] is nums[(i + 1) % n] and the previous element of 
# nums[i] is nums[(i - 1 + n) % n].

# A subarray may only include each element of the fixed buffer nums at most once. 
# Formally, for a subarray nums[i], nums[i + 1], ..., nums[j], 
# there does not exist i <= k1, k2 <= j with k1 % n == k2 % n.

from typing import List

class Solution:
    def maxSubarraySumCircular(self, nums: List[int]) -> int:
        globMax, globMin = nums[0], nums[0]
        curMax, curMin = 0, 0
        total = 0

        for i, n in enumerate(nums):
            curMax = max(curMax + n, n)
            curMin = min(curMin + n, n)
            total += n
            globMax = max(curMax, globMax)
            globMin = min(curMin, globMin)

        return max(globMax, total - globMin) if globMax > 0 else globMax
    
    