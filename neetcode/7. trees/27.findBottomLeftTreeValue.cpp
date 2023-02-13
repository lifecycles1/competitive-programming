// Given the root of a binary tree, return the leftmost value in the last row of the tree. 

#include <limits.h>

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right): val(x), left(left), right(right) {}
};

class Solution {
public:
  int findBottomLeftValue(TreeNode* root) {
    int res = root->val;
    dfs(root, 0, res);
    return res;
  }
private:
  void dfs(TreeNode* root, int level, int& res) {
    if (root == NULL) {
      return;
    }
    if (level > maxLevel) {
      maxLevel = level;
      res = root->val;
    }
    dfs(root->left, level + 1, res);
    dfs(root->right, level + 1, res);
  }
  int maxLevel = -1;
};

