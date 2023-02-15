# Given an array of strings nums containing n unique binary strings each of length n, 
# return a binary string of length n that does not appear in nums. If there are multiple answers, 
# you may return any of them.

from typing import List

class Solution:
  def findDifferentBinaryString(self, nums: List[str]) -> str:
    strSet = { s for s in nums }
    return self.backtrack(0, ["0" for s in nums], strSet, nums)
  
  def backtrack(self, i, curr, strSet, nums):
    if i == len(nums):
      res = "".join(curr)
      return None if res in strSet else res
    
    res = self.backtrack(i+1, curr, strSet, nums)
    if res: return res

    curr[i] = "1"
    res = self.backtrack(i+1, curr, strSet, nums)
    if res: return res
