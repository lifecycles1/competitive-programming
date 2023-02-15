# The n-queens puzzle is the problem of placing n queens on an n x n chessboard such 
# that no two queens attack each other.

# Given an integer n, return the number of distinct solutions to the n-queens puzzle.

from typing import List

class Solution:
  def totalNQueens(self, n: int) -> int:
    answer = [0] # use list to pass by reference
    
    cols = set() # use set to check if a column is occupied
    posdiag = set() # use set to check if a positive diagonal is occupied
    negdiag = set() # use set to check if a negative diagonal is occupied

    self.backtrack(0, n, answer, cols, posdiag, negdiag)
    return answer[0]

  def backtrack(self, i: int, n: int, answer: List[int], cols: set, posdiag: set, negdiag: set) -> None:
    if i == n:
      answer[0] += 1
      return
    
    for j in range(n):
      if j in cols or (i+j) in posdiag or (i-j) in negdiag:
        continue

      cols.add(j)
      posdiag.add(i+j)
      negdiag.add(i-j)

      self.backtrack(i+1, n, answer, cols, posdiag, negdiag)

      cols.remove(j)
      posdiag.remove(i+j)
      negdiag.remove(i-j)

