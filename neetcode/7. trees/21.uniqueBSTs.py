
# Given an integer n, return the number of structurally unique BST's (binary search trees) which has 
# exactly n nodes of unique values from 1 to n.

class TreeNode:
  def __init__(self, val=0, left=None, right=None):
    self.val = val
    self.left = left
    self.right = right

class Solution:
  def numTrees(self, n: int) -> int:
    if n == 0:
      return 0
    dp = [0] * (n + 1)
    dp[0] = 1
    dp[1] = 1
    for i in range(2, n + 1):
      for j in range(1, i + 1):
        dp[i] += dp[j - 1] * dp[i - j]
    return dp[n]

# similar dp as above
class Solution:
  def numTrees(self, n: int) -> int:
    # numTree[4] = numTree[0] * numTree[3] +
    #              numTree[1] * numTree[2] +
    #              numTree[2] * numTree[1] +
    #              numTree[3] * numTree[1]
    numTree = [1] * (n + 1)
    # 0 nodes = 1 tree
    # 1 node = 1 tree
    for nodes in range(2, n + 1):
      total = 0
      for root in range(1, nodes + 1):
        left = root - 1
        right = nodes - root
        total += numTree[left] * numTree[right]
      numTree[nodes] = total
    return numTree[n]