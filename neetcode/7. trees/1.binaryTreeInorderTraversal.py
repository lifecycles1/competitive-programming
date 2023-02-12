# Given the root of a binary tree, return the inorder traversal of its nodes' values.

from typing import List

# Definition for a binary tree node.
class TreeNode:
  def __init__(self, val=0, left=None, right=None):
    self.val = val
    self.left = left
    self.right = right

# Recursive algorithm: time complexity: O(n)
class Solution:
  def inorderTraversal(self, root: TreeNode) -> List[int]:
    res = []

    def inorder(root):
      if not root:
        return
      inorder(root.left)
      res.append(root.val)
      inorder(root.right)
    
    inorder(root)
    return res

# Iterative algorithm: time complexity: O(n)
class Solution:
  def inorderTraversal(self, root: TreeNode) -> List[int]:
    res = []
    stack = []
    while root or stack:
      while root:
        stack.append(root)
        root = root.left
      root = stack.pop()
      res.append(root.val)
      root = root.right
    return res