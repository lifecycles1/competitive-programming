# Given the root of a binary tree, imagine yourself standing on the right side of it, return the 
# values of the nodes you can see ordered from top to bottom.

import collections


class TreeNode:
  def __init__(self, val=0, left=None, right=None):
    self.val = val
    self.left = left
    self.right = right

class Solution:
  def rightSideView(self, root: TreeNode) -> List[int]:
    res = []
    q = collections.deque([root])
    while q:
      rightSide = None
      qLen = len(q)
      for _ in range(qLen):
        node = q.popleft()
        if node:
          rightSide = node
          q.append(node.left)
          q.append(node.right)
      if rightSide:
        res.append(rightSide.val)
    return res