# You are given the root of a binary tree containing digits from 0 to 9 only.

# Each root-to-leaf path in the tree represents a number.

# For example, the root-to-leaf path 1 -> 2 -> 3 represents the number 123.
# Return the total sum of all root-to-leaf numbers. Test cases are generated so that the answer 
# will fit in a 32-bit integer.

# A leaf node is a node with no children.

class TreeNode:
  def __init__(self, val=0, left=None, right=None):
    self.val = val
    self.left = left
    self.right = right

# time complexity: O(n)
class Solution:
  def sumNumbers(self, root: TreeNode) -> int:
    def dfs(node, path):
      if not node:
        return 0
      path = path * 10 + node.val
      if not node.left and not node.right:
        return path
      return dfs(node.left, path) + dfs(node.right, path)
    return dfs(root, 0)