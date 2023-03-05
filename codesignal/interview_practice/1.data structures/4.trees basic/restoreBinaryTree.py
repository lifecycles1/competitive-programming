#
# Binary trees are already defined with this interface:
# class Tree(object):
#   def __init__(self, x):
#     self.value = x
#     self.left = None
#     self.right = None
    
# Python solution 1

def solution(inorder, preorder):
    # base case: if either list is empty, return None
    if not preorder or not inorder:
        return None

    # the first element in the preorder traversal is the root
    root_val = preorder[0]
    root = Tree(root_val)

    # find the index of the root in the inorder traversal
    root_index = inorder.index(root_val)

    # the elements that appear before the root in the inorder traversal belong
    # to the left subtree, and the elements that appear after the root belong
    # to the right subtree
    left_inorder = inorder[:root_index]
    right_inorder = inorder[root_index+1:]

    # the elements in the preorder traversal that follow the root correspond to
    # the left and right subtrees
    left_preorder = preorder[1:1+len(left_inorder)]
    right_preorder = preorder[1+len(left_inorder):]

    # recursively build the left and right subtrees
    root.left = solution(left_inorder, left_preorder)
    root.right = solution(right_inorder, right_preorder)

    return root
    

# Python solution 2

# def solution(inorder, preorder):
#   pre_index = 0
#   in_order_map = {}
#   for i, val in enumerate(inorder):
#     in_order_map[val] = i
  
#   def build_tree(start, end):
#     nonlocal pre_index
#     if start > end: return None
#     root = Tree(preorder[pre_index])
#     pre_index += 1
#     in_index = in_order_map[root.value]
#     root.left = build_tree(start, in_index - 1)
#     root.right = build_tree(in_index + 1, end)
#     return root

#   return build_tree(0, len(inorder) - 1)


# Python solution 3 is the same as 2 but with validation to check if the input is valid 

# def solution(inorder, preorder):
#     if not inorder or not preorder:
#         return None
#     if len(inorder) != len(preorder):
#         raise ValueError("Invalid input. Inorder and preorder traversals should have the same length.")
#     pre_index = 0
#     inorder_map = {}
#     for i, val in enumerate(inorder):
#         inorder_map[val] = i

#     def helper(start, end):
#         nonlocal pre_index
#         if start > end:
#             return None
#         root_val = preorder[pre_index]
#         if root_val not in inorder_map:
#             raise ValueError("Invalid input. Root value should be present in the inorder traversal.")
#         in_index = inorder_map[root_val]
#         if in_index < start or in_index > end:
#             raise ValueError("Invalid input. Root value should be in the range of the current subtree.")
#         root = Tree(root_val)
#         pre_index += 1

#         root.left = helper(start, in_index - 1)
#         root.right = helper(in_index + 1, end)

#         return root

#     return helper(0, len(inorder) - 1)
