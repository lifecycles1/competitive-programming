// Given the root of a binary tree, determine if it is a valid binary search tree (BST).

// A valid BST is defined as follows:

// The left subtree of a node contains only nodes with keys less than the node's key.
// The right subtree of a node contains only nodes with keys greater than the node's key.
// Both the left and right subtrees must also be binary search trees.

#include <limits.h>

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
  bool isValidBST(TreeNode* root) {
    return helper(root, LONG_MIN, LONG_MAX);
  }
private:
  bool helper(TreeNode* root, long left, long right) {
    if (!root)
      return true;
    if (root->val < right && root->val > left) {
      return helper(root->left, left, root->val) && helper(root->right, root->val, right);
    }
    return false;
  }
};

// Solution 2
class Solution2 {
public:
  bool isValidBST(TreeNode* root) {
    TreeNode* prev = NULL;
    return inorder(root, prev);
  }
private:
  bool inorder(TreeNode* root, TreeNode*& prev) {
    if (root == NULL) {
      return true;
    }
    if (!inorder(root->left, prev)) {
      return false;
    }
    if (prev != NULL && prev->val >= root->val) {
      return false;
    }
    prev = root;
    if (!inorder(root->right, prev)) {
      return false;
    }
    return true;
  }
};