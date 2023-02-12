# Given the head of a singly linked list, sort the list using insertion sort, and return the sorted 
# list's head.

# The steps of the insertion sort algorithm:

# Insertion sort iterates, consuming one input element each repetition and growing a sorted output list.
# At each iteration, insertion sort removes one element from the input data, finds the location it 
# belongs within the sorted list and inserts it there.
# It repeats until no input elements remain.
# The following is a graphical example of the insertion sort algorithm. The partially sorted list 
# (black) initially contains only the first element in the list. One element (red) is removed from 
# the input data and inserted in-place into the sorted list with each iteration.

# Definition for singly-linked list.
class ListNode:
  def __init__(self, val=0, next=None):
    self.val = val
    self.next = next

# 1 pointer
class Solution:
  def insertionSortList(self, head: ListNode) -> ListNode:
    dummy = ListNode(0, head)
    cur = head 
    while cur and cur.next:
      if cur.val > cur.next.val:
        pre = dummy
        while pre.next.val < cur.next.val:
          pre = pre.next
        tmp = cur.next
        cur.next = tmp.next
        tmp.next = pre.next
        pre.next = tmp
      else:
        cur = cur.next
    return dummy.next

# 2 pointers
class Solution:
  def insertionSortList(self, head: ListNode) -> ListNode:
    dummy = ListNode(0, head)
    prev, cur = head, head.next

    while cur:
      if cur.val >= prev.val: # maybe they are in the correct order so we continue but we need to update prev and cur to the next nodes
        prev, cur = cur, cur.next
        continue
      # if they are not in the correct order
      # start from the beginning of the linked list
      tmp = dummy
      while cur.val > tmp.next.val:
        tmp = tmp.next

      prev.next = cur.next # update pointer
      # take cur and insert it inbetween tmp and tmp.next
      cur.next = tmp.next
      tmp.next = cur
      # advance our current pointer
      cur = prev.next
    return dummy.next