// Given the head of a singly linked list and two integers left and right where left <= right, 
// reverse the nodes of the list from position left to position right, and return the reversed list.

struct ListNode {
  int val;
  ListNode *next;
  ListNode () : val(0), next(nullptr) {}
  ListNode (int x) : val(x), next(nullptr) {}
  ListNode (int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
  ListNode *reverseBetween(ListNode *head, int left, int right) {
    if (!head || !head->next || left == right) return head;

    ListNode *dummy = new ListNode(0, head);
    ListNode *pre = dummy;
    for (int i = 0; i < left - 1; i++) {
      pre = pre->next;
    }

    ListNode *cur = pre->next;
    for (int i = 0; i < right - left; i++) {
      ListNode *next = cur->next;
      cur->next = next->next;
      next->next = pre->next;
      pre->next = next;
    }

    return dummy->next;
  }
};