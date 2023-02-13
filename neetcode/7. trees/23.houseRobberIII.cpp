# include <algorithm>
# include <utility>


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
  int rob(TreeNode* root) {
    auto result = dfs(root);
    return std::max(result.first, result.second);
  }

private:
  std::pair<int, int> dfs(TreeNode* node) {
    if (!node) return {0, 0};
    auto left = dfs(node->left);
    auto right = dfs(node->right);
    return {std::max(left.first, left.second) + std::max(right.first, right.second),
            node->val + left.first + right.first};
  }
};




