# Given the root of a binary tree, return the level order traversal of its nodes' values. 
# (i.e., from left to right, level by level).

import collections


class TreeNode:
  def __init__(self, val=0, left=None, right=None):
    self.val = val
    self.left = left
    self.right = right

class Solution:
  def levelOrder(self, root: TreeNode) -> List[List[int]]:
    res = []
    q = collections.deque()
    if root:
      q.append(root)
    
    while q:
      val = []
      for _ in range(len(q)):
        node = q.popleft()
        val.append(node.val)
        if node.left:
          q.append(node.left)
        if node.right:
          q.append(node.right)
      res.append(val)
    return res