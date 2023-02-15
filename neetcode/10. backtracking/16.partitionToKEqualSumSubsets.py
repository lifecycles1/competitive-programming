# Given an integer array nums and an integer k, return true if it is possible to divide 
# this array into k non-empty subsets whose sums are all equal.

from typing import List

class Solution:
  def canPartitionKSubsets(self, nums: List[int], k: int) -> bool:
    if sum(nums) % k != 0:
      return False
    
    nums.sort(reverse = True)
    target = sum(nums) / k
    visited = set()
    return self.backtrack(0, 0, 0, k, target, visited, nums)

  def backtrack(self, idx: int, count: int, currSum: int, k: int, target: int, visited: set, nums: List[int]) -> bool:
    if count == k:
      return True
    
    if target == currSum:
      return self.backtrack(0, count + 1, 0, k, target, visited, nums)
    
    for i in range(idx, len(nums)):
      # skip duplicates if last same number was skipped
      if i > 0 and (i-1) not in visited and nums[i] == nums[i-1]:
        continue

      if i in visited or currSum + nums[i] > target:
        continue

      visited.add(i)

      if self.backtrack(i + 1, count, currSum + nums[i], k, target, visited, nums):
        return True
      
      visited.remove(i)

    return False