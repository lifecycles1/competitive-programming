// You are given a perfect binary tree where all leaves are on the same level, and every parent has 
// two children. The binary tree has the following definition:

// struct Node {
//   int val;
//   Node *left;
//   Node *right;
//   Node *next;
// }
// Populate each next pointer to point to its next right node. If there is no next right node, 
// the next pointer should be set to NULL.

// Initially, all next pointers are set to NULL

// Definition for a Node.

#include <limits.h>
#include <queue>


class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;
    Node() {
      val = 0;
      left = NULL;
      right = NULL;
      next = NULL;
    }
    Node(int _val) {
      val = _val;
      left = NULL;
      right = NULL;
      next = NULL;
    }
    Node(int _val, Node* _left, Node* _right, Node* _next) {
      val = _val;
      left = _left;
      right = _right;
      next = _next;
    }
};

class Solution {
public:
  Node* connect(Node* root) {
    Node* cur = root;
    Node* nxt = root ? root->left : nullptr;

    while (cur && nxt) {
      cur->left->next = cur->right;
      if (cur->next) {
        cur->right->next = cur->next->left;
      }
      cur = cur->next;
      if (!cur) {
        cur = nxt;
        nxt = cur->left;
      }
    }
    return root;
  }
};

class Solution {
public:
  Node* connect(Node* root) {
    if (!root) return nullptr;
    std::queue<Node*> q;
    q.push(root);
    while (size(q)) {
      Node* rightNode = nullptr;
      for (int i = size(q); i; i--) {
        auto cur = q.front();
        q.pop();
        cur->next = rightNode;
        rightNode = cur;
        if (cur->right) {
          q.push(cur->right);
          q.push(cur->left);
        }
      }
    }
    return root;
  }
};

class Solution {
public:
  Node* connect(Node* root) {
    if(root && root->left) {
      root->left->next = root->right;
      auto c1 = root->left, c2 = root->right;
      while(c1->right) {
        c1->right->next = c2->left;
        c1 = c1->right;
        c2 = c2->left;
      }
      root->left = connect(root->left);
      root->right = connect(root->right);
    }
    return root;
  }
};