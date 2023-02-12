// Given the head of a linked list and a value x, partition it such that all nodes less than x 
// come before nodes greater than or equal to x.

// You should preserve the original relative order of the nodes in each of the two partitions.

#include <limits.h>

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(NULL) {}
  ListNode(int x) : val(x), next(NULL) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
  ListNode *partition(ListNode *head, int x) {
    ListNode *left = new ListNode(INT_MIN);
    ListNode *right = new ListNode(INT_MIN);
    ListNode *ltail = left;
    ListNode *rtail = right;

    while (head) {
      if (head->val < x) {
        ltail->next = head;
        ltail = ltail->next;
      } else {
        rtail->next = head;
        rtail = rtail->next;
      }
      head = head->next;

      ltail->next = right->next;
      rtail->next = NULL;
    }
    return left->next;
  }
};