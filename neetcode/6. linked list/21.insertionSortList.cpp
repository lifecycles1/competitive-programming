struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
  ListNode *insertionSortList(ListNode *head) {
    if (head == nullptr || head->next == nullptr) {
      return head;
    }
    ListNode *dummy = new ListNode(0);
    dummy->next = head;
    ListNode* prev = head;
    ListNode* cur = head->next;
    while (cur) {
      if (cur->val >= prev->val) {
        prev = cur;
        cur = cur->next;
        continue;
      }
      ListNode* tmp = dummy;
      while (cur->val > tmp->next->val) {
        tmp = tmp->next;
      }
      prev->next = cur->next;
      cur->next = tmp->next;
      tmp->next = cur;
      cur = prev->next;
    }
    return dummy->next;
  }
};