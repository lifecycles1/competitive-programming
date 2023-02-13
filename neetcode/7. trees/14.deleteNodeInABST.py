# Given a root node reference of a BST and a key, delete the node with the given key in the BST. 
# Return the root node reference (possibly updated) of the BST.

# Basically, the deletion can be divided into two stages:

# Search for a node to remove.
# If the node is found, delete the node.

class TreeNode:
  def __init__(self, val=0, left=None, right=None):
    self.val = val
    self.left = left
    self.right = right

class Solution:
  def deleteNode(self, root: TreeNode, key: int) -> TreeNode:
    if not root:
      return root
    if root.val == key:
      if not root.left:
        return root.right
      if not root.right:
        return root.left
      node = root.right
      while node.left:
        node = node.left
      node.left = root.left
      return root.right
    if root.val < key:
      root.right = self.deleteNode(root.right, key)
    else:
      root.left = self.deleteNode(root.left, key)
    return root