# You are given two integers n and k and two integer arrays speed and efficiency both of length n. 
# There are n engineers numbered from 1 to n. speed[i] and efficiency[i] represent the speed 
# and efficiency of the ith engineer respectively.

# Choose at most k different engineers out of the n engineers to form a team with the maximum performance.

# The performance of a team is the sum of their engineers' speeds multiplied by the minimum 
# efficiency among their engineers.

# Return the maximum performance of this team. Since the answer can be a huge number, 
# return it modulo 109 + 7.

from typing import List
import heapq

class Solution:
  def maxPerformance(self, n: int, speed: List[int], efficiency: List[int], k: int) -> int:
    # sort by efficiency
    # use a heap to store the speed of the k engineers with the lowest speed
    # pop the lowest speed if the heap size is greater than k
    # update the maximum performance
    # time complexity: O(nlogn)
    # space complexity: O(n)
    # 1 <= n <= 105
    # 1 <= k <= n
    # speed.length == n
    # efficiency.length == n
    # 1 <= speed[i] <= 105
    # 1 <= efficiency[i] <= 108
    # 10^9 + 7
    MOD = 10**9 + 7
    # sort by efficiency
    engineers = sorted(zip(efficiency, speed), reverse=True)
    # use a heap to store the speed of the k engineers with the lowest speed
    heap = []
    # the sum of the speed of the k engineers with the lowest speed
    speedSum = 0
    # the maximum performance
    maxPerformance = 0
    for e, s in engineers:
      # add the speed to the heap
      heapq.heappush(heap, s)
      # update the sum of the speed of the k engineers with the lowest speed
      speedSum += s
      # if the heap size is greater than k
      if len(heap) > k:
        # pop the lowest speed
        speedSum -= heapq.heappop(heap)
      # update the maximum performance
      maxPerformance = max(maxPerformance, speedSum * e)
    return maxPerformance % MOD