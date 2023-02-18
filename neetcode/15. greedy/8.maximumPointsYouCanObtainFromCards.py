# There are several cards arranged in a row, and each card has an associated number of points. 
# The points are given in the integer array cardPoints.

# In one step, you can take one card from the beginning or from the end of the row. 
# You have to take exactly k cards.

# Your score is the sum of the points of the cards you have taken.

# Given the integer array cardPoints and the integer k, return the maximum score you can obtain.

from typing import List

# sliding window
class Solution:
    def maxScore(self, C: List[int], K: int) -> int:
        best = total = sum(C[:K])
        for i in range (K-1, -1, -1):
            total += C[i + len(C) - K] - C[i]
            best = max(best, total)
        return best
    
# two pointers
class Solution:
   def maxScore(self, cp: List[int], k: int) -> int:
        ans = tot_sum = sum(cp[:k])
        for i in range(1,k+1):
            ans = max(ans, tot_sum := tot_sum + cp[len(cp)-i] - cp[k-i])        
        return ans
   

class Solution:
    def maxScore(self, cardPoints: List[int], k: int) -> int:
        size = len(cardPoints) - k
        minSubArraySum = curr = sum(cardPoints[:size])
        
        for i in range(len(cardPoints) - size):
            curr += cardPoints[size + i] - cardPoints[i]
            minSubArraySum = min(minSubArraySum, curr)
            
        return sum(cardPoints) - minSubArraySum

# sliding window. fastest so far
class Solution:
    def maxScore(self, cardPoints: List[int], k: int) -> int:
        n = len(cardPoints)
        total = sum(cardPoints)
        
        remaining_length = n - k
        subarray_sum = sum(cardPoints[:remaining_length])
        
        min_sum = subarray_sum
        for i in range(remaining_length, n):
            # Update the sliding window sum to the subarray ending at index i
            subarray_sum += cardPoints[i]
            subarray_sum -= cardPoints[i - remaining_length]
            # Update min_sum to track the overall minimum sum so far
            min_sum = min(min_sum, subarray_sum)
        return total - min_sum