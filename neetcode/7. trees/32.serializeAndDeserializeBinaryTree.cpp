// Serialization is the process of converting a data structure or object into a sequence of bits so 
// that it can be stored in a file or memory buffer, or transmitted across a network connection link 
// to be reconstructed later in the same or another computer environment.

// Design an algorithm to serialize and deserialize a binary tree. There is no restriction on how your 
// serialization/deserialization algorithm should work. You just need to ensure that a binary tree can 
// be serialized to a string and this string can be deserialized to the original tree structure.

// Clarification: The input/output format is the same as how LeetCode serializes a binary tree. You do 
// not necessarily need to follow this format, so please be creative and come up with different 
// approaches yourself.


// Design an algorithm to serialize & deserialize a binary tree
// Use stringstream to concisely handle negatives, nulls, etc.
// Time: O(n) serialize, O(n) deserialize
// Space: O(n) serialize, O(n) deserialize

#include <limits.h>
#include <string>
#include <sstream>
using namespace std;


struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Codec {
public:
  // encodes a tree to a single string.
  string serialize(TreeNode* root) {
    ostringstream out;
    encode(root, out);
    return out.str();
  }

  // decodes your encoded data to tree.
  TreeNode* deserialize(string data) {
    istringstream in(data);
    return decode(in);
  }

private:
  void encode(TreeNode* root, ostringstream& out) {
    if (root == NULL) {
      out << "N ";
      return;
    }
    out << root->val << " ";

    encode(root->left, out);
    encode(root->right, out);
  }

  TreeNode* decode(istringstream& in) {
    string value = "";
    in >> value;
    if (value == "N") {
      return NULL;
    }
    TreeNode* root = new TreeNode(stoi(value));
    root->left = decode(in);
    root->right = decode(in);
    return root;
  }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));