// Given the head of a sorted linked list, delete all duplicates such that each element 
// appears only once. Return the linked list sorted as well.

// Time Complexity is O(N).
// Space Complexity is O(1).

#include <limits.h>

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
  ListNode* deleteDuplicates(ListNode* head) {
    ListNode *fast = head;
    ListNode *slow = head;

    while (slow != NULL) {
      while (fast != NULL && slow->val == fast->val) {
        fast = fast->next;
      }
      slow->next = fast;
      slow = slow->next;
    }
    return head;
  }
};

class Solution {
public:
  ListNode* deleteDuplicates(ListNode* head) {
    ListNode *cur = head;
    while (cur) {
      while (cur->next && cur->val == cur->next->val) {
        cur->next = cur->next->next;
      }
      cur = cur->next;
    }
    return head;
  }
};