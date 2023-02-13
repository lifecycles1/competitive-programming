# Given an integer array nums where the elements are sorted in ascending order, convert it to a height-balanced binary search tree.

# definition for a binary tree node.
class TreeNode:
  def __init__(self, val=0, left=None, right=None):
    self.val = val
    self.left = left
    self.right = right

class Solution:
  def sortedArrayToBST(self, nums: List[int]) -> TreeNode:
    if not nums:
      return None
    mid = len(nums) // 2
    root = TreeNode(nums[mid])
    root.left = self.sortedArrayToBST(nums[:mid])
    root.right = self.sortedArrayToBST(nums[mid+1:])
    return root

# almost the same as the above solution, but with a helper function
class Solution:
  def sortedArrayToBST(self, nums: List[int]) -> TreeNode:
    def helper(l, r):
      if l > r:
        return None
      m = (l + r) // 2
      root = TreeNode(nums[m])
      root.left = helper(l, m-1)
      root.right = helper(m+1, r)
      return root
    return helper(0, len(nums)-1)