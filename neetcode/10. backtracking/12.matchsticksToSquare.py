# You are given an integer array matchsticks where matchsticks[i] is the length of the ith matchstick. 
# You want to use all the matchsticks to make one square. You should not break any stick, 
# but you can link them up, and each matchstick must be used exactly one time.

# Return true if you can make this square and false otherwise.

from typing import List

class Solution:
  def makesquare(self, matchsticks: List[int]) -> bool:
    length = sum(matchsticks) // 4
    sides = [0] * 4

    if sum(matchsticks) / 4 != length:
      return False
    
    matchsticks.sort(reverse=True)

    def backtrack(i):
      if i == len(matchsticks):
        return True
      
      for j in range(4):
        if sides[j] + matchsticks[i] <= length:
          sides[j] += matchsticks[i]
          if backtrack(i+1):
            return True
          sides[j] -= matchsticks[i]
      return False
    
    return backtrack(0)