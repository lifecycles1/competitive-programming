// Given the head of a linked list and an integer val, remove all the nodes of the linked list 
// that has Node.val == val, and return the new head.

//  * Definition for singly-linked list.
struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
  ListNode* removeElements(ListNode* head, int val) {
    ListNode *dummy = new ListNode(0, head);
    ListNode *prev = dummy;
    ListNode *curr = head;

    while (curr) {
      ListNode *nxt = curr->next;

      if (curr->val == val) {
        prev->next = nxt;
      } else {
        prev = curr;
      }
      curr = nxt;
    }
    return dummy->next;
  }
};