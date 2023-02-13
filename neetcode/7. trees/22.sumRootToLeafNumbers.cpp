# include <limits.h>

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
  int sumNumbers(TreeNode* root) {
    return sumNumbers(root, 0);
  }
private:
  int sumNumbers(TreeNode* root, int sum) {
    if (root == NULL) {
      return 0;
    }
    sum = sum * 10 + root->val;
    if (root->left == NULL && root->right == NULL) {
      return sum;
    }
    return sumNumbers(root->left, sum) + sumNumbers(root->right, sum);
  }
};