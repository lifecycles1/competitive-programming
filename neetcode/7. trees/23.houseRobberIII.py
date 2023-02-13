# The thief has found himself a new place for his thievery again. There is only one entrance to this area, 
# called root.

# Besides the root, each house has one and only one parent house. After a tour, the smart thief 
# realized that all houses in this place form a binary tree. It will automatically contact the police 
# if two directly-linked houses were broken into on the same night.

# Given the root of the binary tree, return the maximum amount of money the thief can rob without 
# alerting the police.

class TreeNode:
  def __init__(self, val=0, left=None, right=None):
    self.val = val
    self.left = left
    self.right = right

# faster
class Solution:
  def rob(self, root: TreeNode) -> int:
    def dfs(node):
      if not node:
        return 0, 0
      left = dfs(node.left)
      right = dfs(node.right)
      return max(left) + max(right), node.val + left[0] + right[0]
    return max(dfs(root))

# modified dfs 
class Solution:
  def rob(self, root: TreeNode) -> int:
    # return pair: [withRoot, withoutRoot]
    def dfs(root):
      if not root:
        return [0, 0]
      leftPair = dfs(root.left)
      rightPair = dfs(root.right)

      withRoot = root.val + leftPair[1] + rightPair[1]
      withoutRoot = max(leftPair) + max(rightPair)

      return [withRoot, withoutRoot]

    return max(dfs(root))
