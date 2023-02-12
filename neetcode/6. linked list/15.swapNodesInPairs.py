class ListNode:
  def __init__(self, val=0, next=None):
    self.val = val
    self.next = next
  
class Solution:
  def swapPairs(self, head: ListNode) -> ListNode:
    dummy = ListNode(0, head)
    prev, curr = dummy, head

    while curr and curr.next:
      next = curr.next
      curr.next = next.next
      next.next = curr
      prev.next = next
      prev = curr
      curr = curr.next

    return dummy.next