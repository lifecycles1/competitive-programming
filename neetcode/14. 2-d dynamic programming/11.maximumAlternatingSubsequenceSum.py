# The alternating sum of a 0-indexed array is defined as the sum of the elements at even 
# indices minus the sum of the elements at odd indices.

# For example, the alternating sum of [4,2,5,3] is (4 + 5) - (2 + 3) = 4.
# Given an array nums, return the maximum alternating sum of any subsequence of nums 
# (after reindexing the elements of the subsequence).

# A subsequence of an array is a new array generated from the original array by deleting some 
# elements (possibly none) without changing the remaining elements' relative order. For example, 
# [2,7,4] is a subsequence of [4,2,3,7,2,1,4] (the underlined elements), while [2,4,2] is not.

from typing import List

# recursive solution 25% faster
class Solution:
    def maxAlternatingSum(self, nums: List[int]) -> int:
        dp = {}

        # i = index, even = True/False
        def dfs(i, even):
            if i == len(nums):
                return 0
            if (i, even) in dp:
                return dp[(i, even)]
            
            total = nums[i] if even else (-1 * nums[i])
            dp[(i, even)] = max(total + dfs(i+1, not even), dfs(i+1, even))
            return dp[(i, even)]
        return dfs(0, True)
    
# dynamic programming solution 70% faster
class Solution:
    def maxAlternatingSum(self, nums: List[int]) -> int:
        sumEven, sumOdd = 0, 0
        for i in range(len(nums) - 1, -1, -1):
            tmpEven = max(sumOdd + nums[i], sumEven)
            tmpOdd = max(sumEven - nums[i], sumOdd)
            sumEven, sumOdd = tmpEven, tmpOdd
        return sumEven


