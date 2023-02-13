// Given a root node reference of a BST and a key, delete the node with the given key in the BST. 
// Return the root node reference (possibly updated) of the BST.

// Basically, the deletion can be divided into two stages:

// Search for a node to remove.
// If the node is found, delete the node.

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
  TreeNode* deleteNode(TreeNode* root, int key) {
    if (!root) return nullptr;
    if (key < root->val) {
      root->left = deleteNode(root->left, key);
    } else if (key > root->val) {
      root->right = deleteNode(root->right, key);
    } else {
      if (!root->left) {
        TreeNode* right = root->right;
        delete root;
        return right;
      } else if (!root->right) {
        TreeNode* left = root->left;
        delete root;
        return left;
      } else {
        TreeNode* minNode = getMin(root->right);
        root->val = minNode->val;
        root->right = deleteNode(root->right, minNode->val);
      }
    }
    return root;
  }
private:
  TreeNode* getMin(TreeNode* root) {
    while (root->left) {
      root = root->left;
    }
    return root;
  }
};