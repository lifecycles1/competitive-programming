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
  ListNode *rotateRight(ListNode *head, int k) {
    if (!head || !head->next || k == 0) return head;

    ListNode *tail = head;
    int len = 1;
    while (tail->next) {
      tail = tail->next;
      len++;
    }

    k = k % len;
    if (k == 0) return head;

    ListNode *newTail = head;
    for (int i = 0; i < len - k - 1; i++) {
      newTail = newTail->next;
    }

    ListNode *newHead = newTail->next;
    newTail->next = NULL;
    tail->next = head;

    return newHead;
  }
};