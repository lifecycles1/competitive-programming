# Given the head of a linked list, rotate the list to the right by k places.

# Definition for singly-linked list.
class ListNode:
  def __init__(self, val=0, next=None):
    self.val = val
    self.next = next

class Solution:
  def rotateRight(self, head: ListNode, k: int) -> ListNode:
    if not head or not head.next or k == 0:
      return head

    # get the length of the list
    length = 1
    tail = head
    while tail.next:
      length += 1
      tail = tail.next

    # get the actual number of rotations
    k = k % length

    # if k is 0, then no need to rotate
    if k == 0:
      return head

    # get the node right before the new head
    new_tail = head
    for _ in range(length - k - 1):
      new_tail = new_tail.next

    # get the new head
    new_head = new_tail.next

    # break the list
    new_tail.next = None
    tail.next = head

    return new_head