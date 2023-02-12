// Given the head of a singly linked list, return true if it is a palindrome or false otherwise.

# include <vector>

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
  bool isPalindrome(ListNode* head) {
    std::vector<int> v;
    while (head != nullptr) {
      v.push_back(head->val);
      head = head -> next;
    }
    for (int i = 0; i < v.size() / 2; i++) {
      if (v[i] != v[v.size() - i - 1]) {
        return false;
      }
    }
    return true;  
  }
};

// using fast and slow pointer
// floyd's cycle detection algorithm
class Solution {
public:
  bool isPalindrome(ListNode* head) {
    ListNode *slow = head;
    ListNode *fast = head;
    ListNode *prev = nullptr;
    ListNode *temp = nullptr;

    while (fast && fast->next) {
      slow = slow->next;
      fast = fast->next->next;
    }
    prev = slow;
    slow = slow->next;
    prev->next = NULL;
    while (slow) {
      temp = slow->next;
      slow->next = prev;
      prev = slow;
      slow = temp;
    }
    fast = head;
    slow = prev;
    while (slow) {
      if (fast->val != slow->val) {
        return false;
      } else {
        fast = fast->next;
        slow = slow->next;
      }
    }
    return true;
  }
};