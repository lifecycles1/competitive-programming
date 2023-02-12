# Given the head of a linked list and a value x, partition it such that all nodes less than x 
# come before nodes greater than or equal to x.

# You should preserve the original relative order of the nodes in each of the two partitions.

# Definition for singly-linked list.
class ListNode:
  def __init__(self, val=0, next=None):
    self.val = val
    self.next = next

class Solution:
  def partition(self, head: ListNode, x: int) -> ListNode:
    left, right = ListNode(), ListNode() # empty dummy nodes not included in the final result
    ltail, rtail = left, right # always pointing at the last node in our left and right list
    
    # iterate throught the entire input list
    while head:
      if head.val < x:
        ltail.next = head
        ltail = ltail.next
      else:
        rtail.next = head
        rtail = rtail.next
      # move the head to the next node after each iteration
      head = head.next

    # merge the two lists
    # ltail.next is going to point to the first node in the right list
    # rtail.next is going to point to None
    ltail.next = right.next # right.next because right itself is a dummy node so right.next is going to be the real node in the list
    rtail.next = None

    return left.next # return left.next because left itself is a dummy node and left.next is going to be the first node in the list
    