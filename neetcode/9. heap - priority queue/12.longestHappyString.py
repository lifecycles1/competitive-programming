# A string s is called happy if it satisfies the following conditions:

# s only contains the letters 'a', 'b', and 'c'.
# s does not contain any of "aaa", "bbb", or "ccc" as a substring.
# s contains at most a occurrences of the letter 'a'.
# s contains at most b occurrences of the letter 'b'.
# s contains at most c occurrences of the letter 'c'.
# Given three integers a, b, and c, return the longest possible happy string. 
# If there are multiple longest happy strings, return any of them. 
# If there is no such string, return the empty string "".

# A substring is a contiguous sequence of characters within a string.

import heapq

class Solution:
  def longestDiverseString(self, a: int, b: int, c: int) -> str:
    # max heap
    # (count, char)
    pq = []
    if a > 0:
      heapq.heappush(pq, (-a, 'a'))
    if b > 0:
      heapq.heappush(pq, (-b, 'b'))
    if c > 0:
      heapq.heappush(pq, (-c, 'c'))
    
    res = ""
    while pq:
      count, ch = heapq.heappop(pq)
      count = -count

      if len(res) >= 2 and res[-1] == ch and res[-2] == ch:
        if not pq:
          break
        count2, ch2 = heapq.heappop(pq)
        count2 = -count2
        res += ch2
        if count2 > 1:
          heapq.heappush(pq, (-count2 + 1, ch2))
        heapq.heappush(pq, (-count, ch))
      else:
        res += ch
        if count > 1:
          heapq.heappush(pq, (-count + 1, ch))
      
    return res