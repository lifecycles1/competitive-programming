# Given a collection of numbers, nums, that might contain duplicates, 
# return all possible unique permutations in any order.

from typing import List

class Solution:
  def permuteUnique(self, nums: List[int]) -> List[List[int]]:
    res = []
    perm = []
    used = [False] * len(nums)
    nums.sort()
    self.backtrack(nums, used, perm, res)
    return res
  
  def backtrack(self, nums: List[int], used: List[bool], perm: List[int], res: List[List[int]]):
    if len(perm) == len(nums):
      res.append(perm)
      return
    for i in range(len(nums)):
      if used[i] or (i > 0 and nums[i] == nums[i-1] and not used[i-1]):
        continue
      used[i] = True
      perm.append(nums[i])
      self.backtrack(nums, used, perm.copy(), res)
      perm.pop()
      used[i] = False