// Given the heads of two singly linked-lists headA and headB, return the node at which the 
// two lists intersect. If the two linked lists have no intersection at all, return null.

#include <limits.h>

//  * Definition for singly-linked list.
struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
  ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
    ListNode *l1 = headA;
    ListNode *l2 = headB;
    while (l1 != l2) {
      l1 = l1 ? l1->next : headB;
      l2 = l2 ? l2->next : headA;
    }
    return l1;
  }
};