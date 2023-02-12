// Given the root of a binary tree, return the inorder traversal of its nodes' values.

# include <vector>
# include <stack>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode* right) : val(x), left(left), right(right) {}
};

// Recursive solution
class Solution {
public:
  vector<int> inorderTraversal(TreeNode* root) {
    vector<int> result;
    inorder(root, result);
    return result;
  }
private:
  void inorder(TreeNode* root, vector<int>& result) {
    if (root == nullptr) return;
    inorder(root->left, result);
    result.push_back(root->val);
    inorder(root->right, result);
  }
};

// Iterative solution
class Solution {
public:
  vector<int> inorderTraversal(TreeNode* root) {
    vector<int> res;
    stack<TreeNode*> s;
    TreeNode* curr = root;
    while (curr != nullptr || !s.empty()) {
      while (curr != nullptr) {
        s.push(curr);
        curr = curr->left;
      }
      curr = s.top();
      s.pop();
      res.push_back(curr->val);
      curr = curr->right;
    }
    return res;
  }
};