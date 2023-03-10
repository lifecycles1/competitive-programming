// A path in a binary tree is a sequence of nodes where each pair of adjacent nodes in the sequence 
// has an edge connecting them. A node can only appear in the sequence at most once. Note that the 
// path does not need to pass through the root.

// The path sum of a path is the sum of the node's values in the path.

// Given the root of a binary tree, return the maximum path sum of any non-empty path.

#include <limits.h>
#include <algorithm>
using namespace std;

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
  int maxPathSum(TreeNode* root) {
    int maxPath = INT_MIN;
    dfs(root, maxPath);
    return maxPath;
  }
private:
  int dfs(TreeNode* root, int& maxPath) {
    if (root == NULL) {
      return 0;
    }
    int left = max(dfs(root->left, maxPath), 0);
    int right = max(dfs(root->right, maxPath), 0);

    int curPath = root->val + left + right;
    maxPath = max(maxPath, curPath);

    return root->val + max(left, right);
  }
};
