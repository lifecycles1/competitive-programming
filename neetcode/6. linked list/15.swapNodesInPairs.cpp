// Given a linked list, swap every two adjacent nodes and return its head. 
// You must solve the problem without modifying the values in the list's nodes 
// (i.e., only nodes themselves may be changed.)

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
  ListNode* swapPairs(ListNode* head) {
    // if head is NULL or just having a single node, then no need to change anything
    if (head == NULL || head->next == NULL) {
      return head;
    }

    ListNode* temp; // temporary pointer to store head->next
    temp = head->next; // give temp what he wants

    head->next = swapPairs(head->next->next); // changing links
    temp->next = head; // put temp->next to head

    return temp; // now after changing links, temp acts as our head
  }
};

// faster solution
class Solution {
public:
  ListNode* swapPairs(ListNode* head) {
    ListNode dummy(0, head);
    ListNode* prev = &dummy;
    ListNode* cur = head;

    while (cur && cur->next) {
      ListNode* next = cur->next;
      cur->next = next->next;
      next->next = cur;
      prev->next = next;
      prev = cur;
      cur = cur->next;
    }
    return dummy.next;
  }
};