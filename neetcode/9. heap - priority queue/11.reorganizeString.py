# Given a string s, rearrange the characters of s so that any two adjacent characters are not the same.

# Return any possible rearrangement of s or return "" if not possible.

from collections import Counter
import heapq

class Solution:
  def reorganizeString(self, s: str) -> str:
    # heap

    count = Counter(s) # Hashmap, count each char
    maxHeap = [[-cnt, char] for char, cnt in count.items()]
    heapq.heapify(maxHeap) # O(n)

    prev = None
    res = ""
    while maxHeap or prev:
      if prev and not maxHeap:
        return ""
      # most frequent, except prev
      cnt, char = heapq.heappop(maxHeap)
      res += char
      cnt += 1

      if prev:
        heapq.heappush(maxHeap, prev)
        prev = None
      if cnt != 0:
        prev = [cnt, char]
    return res
    #

    # greedy 
    # O(n) time, O(n) space
    # n = len(s)
    # if n == 1:
    #   return s

    # counter = Counter(s)
    # maxCount = max(counter.values())
    # if maxCount > (n + 1) // 2:
    #   return ""

    # res = [None] * n
    # i = 0
    # for c, count in counter.most_common():
    #   while count > 0:
    #     res[i] = c
    #     i += 2
    #     if i >= n:
    #       i = 1
    #     count -= 1
    # return "".join(res)

