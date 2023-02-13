# Given the root of a binary tree, return the leftmost value in the last row of the tree. 

class TreeNode:
  def __init__(self, val=0, left=None, right=None):
    self.val = val
    self.left = left
    self.right = right

class Solution:
  def findBottomLeftValue(self, root: TreeNode) -> int:
    if not root:
      return None
    queue = [root]
    while queue:
      node = queue.pop(0)
      if node.right:
        queue.append(node.right)
      if node.left:
        queue.append(node.left)
    return node.val