// Given the root of a binary search tree, and an integer k, return the kth smallest value 
// (1-indexed) of all the values of the nodes in the tree.


// Inorder traversal, each visit decrement k, when k = 0 return, works because inorder
// Time: O(n)
// Space: O(n)

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
  int kthSmallest(TreeNode* root, int k) {
    int result = 0;
    inorder(root, k, result);
    return result;
  }
private:
  void inorder(TreeNode* root, int& k, int& result) {
    if (root == NULL) {
      return;
    }
    inorder(root->left, k, result);
    k--;
    if (k == 0) {
      result = root->val;
      return;
    }
    inorder(root->right, k, result);
  }
};