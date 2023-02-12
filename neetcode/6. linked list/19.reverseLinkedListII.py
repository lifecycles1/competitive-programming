# Given the head of a singly linked list and two integers left and right where left <= right, 
# reverse the nodes of the list from position left to position right, and return the reversed list.

class ListNode:
  def __init__(self, val=0, next=None):
    self.val = val
    self.next = next

class Solution:
  def reverseBetween(self, head: ListNode, left: int, right: int) -> ListNode:
    if not head or not head.next or left == right:
      return head

    # create a dummy node to point to the head of the list
    dummy = ListNode(0, head)
    # create a prev node to point to the node right before the left node
    prev = dummy
    # create a curr node to point to the left node
    curr = head

    # move the prev and curr nodes to the right position
    for _ in range(left - 1):
      prev = prev.next
      curr = curr.next

    # reverse the nodes between left and right
    for _ in range(right - left):
      # get the node right after the curr node
      temp = curr.next
      # move the node right after the curr node to the right after the prev node
      curr.next = temp.next
      temp.next = prev.next
      prev.next = temp

    return dummy.next