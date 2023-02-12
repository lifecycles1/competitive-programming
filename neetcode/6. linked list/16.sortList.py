class ListNode:
  def __init__(self, val=0, next=None):
    self.val = val
    self.next = next

# sorting a linked list using merge sort technique
class Solution:
  def sortList(self, head: ListNode) -> ListNode:
    if not head or not head.next:
      return head

    # split the list into two halves
    left = head
    right = self.getMid(head)
    tmp = right.next
    right.next = None
    right = tmp

    # sort each half
    left = self.sortList(left)
    right = self.sortList(right)

    # merge the two sorted lists
    return self.merge(left, right)

  def getMid(self, head: ListNode) -> ListNode:
    slow = head
    fast = head.next

    while fast and fast.next:
      slow = slow.next
      fast = fast.next.next

    return slow

  def merge(self, left: ListNode, right: ListNode) -> ListNode:
    tail = dummy = ListNode() # dummy case so that when we merge these two lists, we don't have to deal with the case where one of the list is empty

    while left and right:
      if left.val < right.val:
        tail.next = left
        left = left.next
      else:
        tail.next = right
        right = right.next
      # move the tail to the next node after each iteration
      tail = tail.next
    # when one of the lists is empty, we just need to append the other list to the tail
    if left:
      tail.next = left
    if right:
      tail.next = right

    return dummy.next