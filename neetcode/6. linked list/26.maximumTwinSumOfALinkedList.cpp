// In a linked list of size n, where n is even, the ith node (0-indexed) of the linked list is 
// known as the twin of the (n-1-i)th node, if 0 <= i <= (n / 2) - 1.

// For example, if n = 4, then node 0 is the twin of node 3, and node 1 is the twin of node 2. 
// These are the only nodes with twins for n = 4.
// The twin sum is defined as the sum of a node and its twin.

// Given the head of a linked list with even length, return the maximum twin sum of the linked list.

#include <algorithm>
using namespace std;

// Definition for singly-linked list
struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

bool cmp(ListNode* a, ListNode* b) {
  return a->val < b->val;
}

class Solution {
public:
  int pairSum(ListNode* head) {
    ListNode* slow = head;
    ListNode* fast = head;
    ListNode* prev = nullptr;
    while (fast && fast->next) {
      fast = fast->next->next;
      ListNode* temp = slow->next;
      slow->next = prev;
      prev = slow;
      slow = temp;
    }
    int res = 0;
    while (slow) {
      ListNode* max_node = *std::max_element(&prev, &prev + 1, cmp);
      res = max(res, max_node->val + slow->val);
      prev = prev->next;
      slow = slow->next;
    }
    return res;
  }
};