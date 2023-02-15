# Given two integers n and k, return all possible combinations of k numbers 
# chosen from the range [1, n].

# You may return the answer in any order.

class Solution:
  def combine(self, n: int, k: int) -> List[List[int]]:
    res = []
    comb = []
    self.backtrack(n, k, 1, comb, res)
    return res
  
  def backtrack(self, n: int, k: int, start: int, comb: List[int], res: List[List[int]]):
    if len(comb) == k:
      res.append(comb)
      return
    for i in range(start, n+1):
      comb.append(i)
      self.backtrack(n, k, i+1, comb.copy(), res)
      comb.pop()