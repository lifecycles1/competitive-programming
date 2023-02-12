# Given the roots of two binary trees root and subRoot, return true if there is a subtree of root 
# with the same structure and node values of subRoot and false otherwise.

# A subtree of a binary tree tree is a tree that consists of a node in tree and all of this node's 
# descendants. The tree tree could also be considered as a subtree of itself.

class TreeNode:
  def __init__(self, val=0, left=None, right=None):
    self.val = val
    self.left = left
    self.right = right

class Solution:
  def isSubtree(self, root:Optional[TreeNode], subRoot: Optional[TreeNode]) -> bool:
    if subRoot is None:
      return True
    if root is None:
      return False
    if (root.val == subRoot.val) and self.isIdentical(root, subRoot):
      return True
    return self.isSubtree(root.left, subRoot) or self.isSubtree(root.right, subRoot)
  
  def isIdentical(self, root:Optional[TreeNode], subRoot: Optional[TreeNode]) -> bool:
    if root is None and subRoot is None:
      return True 
    if root is None or subRoot is None:
      return False
    if root.val != subRoot.val:
      return False
    return self.isIdentical(root.left, subRoot.left) and self.isIdentical(root.right, subRoot.right)