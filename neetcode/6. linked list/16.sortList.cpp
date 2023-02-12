// Given the head of a linked list, return the list after sorting it in ascending order.

#include <limits.h>

// Definition for singly-linked list.
struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// merge sort technique
class Solution {
public:
  ListNode *sortList(ListNode *head) {
    if (head == NULL || head->next == NULL) {
      return head;
    }

    // split the list into two halves
    ListNode *left = head;
    ListNode *right = getMid(head);
    ListNode *tmp = right->next;
    right->next = NULL;
    right = tmp;

    // sort each half
    left = sortList(left);
    right = sortList(right);

    // merge the two sorted lists
    return merge(left, right);
  }
private:
  ListNode *getMid(ListNode *head) {
    ListNode *slow = head;
    ListNode *fast = head->next;

    while (fast != NULL && fast->next != NULL) {
      slow = slow->next;
      fast = fast->next->next;
    }
    return slow;
  }

  ListNode *merge(ListNode *left, ListNode *right) {
    ListNode *dummy = new ListNode(INT_MIN);
    ListNode *tail = dummy;

    while (left != NULL && right != NULL) {
      if (left->val < right->val) {
        tail->next = left;
        left = left->next;
      } else {
        tail->next = right;
        right = right->next;
      }
      // move the tail to the next node after each iteration
      tail = tail->next;
    }
    // when one of the lists is empty, we just need to append the other list to the tail
    if (left != NULL) {
      tail->next = left;
    }
    if (right != NULL) {
      tail->next = right;
    }
    return dummy->next;
  }
};