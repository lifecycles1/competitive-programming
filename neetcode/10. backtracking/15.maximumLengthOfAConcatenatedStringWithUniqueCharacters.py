# You are given an array of strings arr. A string s is formed by the concatenation of a 
# subsequence of arr that has unique characters.

# Return the maximum possible length of s.

# A subsequence is an array that can be derived from another array by deleting some or no 
# elements without changing the order of the remaining elements.

from typing import List
from collections import Counter

class Solution:
  def maxLength(self, arr: List[str]) -> int:
    charSet = set()
    return self.backtrack(0, charSet, arr)

  def overlap(self, charSet: set, s: str) -> bool:
    # c = Counter(charSet) + Counter(s)
    # return max(c.values()) > 1
    prev = set()
    for c in s:
      if c in charSet or c in prev:
        return True
      prev.add(c)
    return False

  def backtrack(self, i: int, charSet: set, arr: List[str]) -> int:
    if i == len(arr):
      return len(charSet)
    res = 0
    if not self.overlap(charSet, arr[i]):
      for c in arr[i]:
        charSet.add(c)
      res = self.backtrack(i+1, charSet, arr)
      for c in arr[i]:
        charSet.remove(c)
    return max(res, self.backtrack(i+1, charSet, arr)) # dont  concatenate arr[i]