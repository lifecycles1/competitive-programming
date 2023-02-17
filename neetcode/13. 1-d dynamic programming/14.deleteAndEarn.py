# You are given an integer array nums. You want to maximize the number of points you 
# get by performing the following operation any number of times:

# Pick any nums[i] and delete it to earn nums[i] points. Afterwards, you must delete every 
# element equal to nums[i] - 1 and every element equal to nums[i] + 1.
# Return the maximum number of points you can earn by applying the above operation some number of times.

# House Robber Style
# Time Complexity O(n)
# Space Complexity O(n)

class Solution:
    def deleteAndEarn(self, nums):
        upperLimit = max(nums) + 1
        store = [0] * upperLimit

        for num in nums:
            store[num] += num
        
        dp = [0] * upperLimit

        dp[1] = 1 * store[1]
        for i in range(2, upperLimit):
            dp[i] = max(dp[i-2] + store[i], dp[i-1])

        return dp[-1]