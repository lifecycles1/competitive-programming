# Suppose LeetCode will start its IPO soon. In order to sell a good price of its shares to Venture 
# Capital, LeetCode would like to work on some projects to increase its capital before the IPO. 
# Since it has limited resources, it can only finish at most k distinct projects before the IPO. 
# Help LeetCode design the best way to maximize its total capital after finishing at most k distinct
# projects.

# You are given n projects where the ith project has a pure profit profits[i] and a minimum capital 
# of capital[i] is needed to start it.

# Initially, you have w capital. When you finish a project, you will obtain its pure profit and the 
# profit will be added to your total capital.

# Pick a list of at most k distinct projects from given projects to maximize your final capital, 
# and return the final maximized capital.

# The answer is guaranteed to fit in a 32-bit signed integer.

from typing import List
import heapq

class Solution:
    def findMaximizedCapital(self, k: int, w: int, profits: List[int], capital: List[int]) -> int:
        # sort by capital
        projects = sorted(zip(capital, profits))
        # max heap
        heap = []
        i = 0
        for _ in range(k):
            # add all projects that can be selected within the available capital
            while i < len(projects) and projects[i][0] <= w:
                heapq.heappush(heap, -projects[i][1])
                i += 1
            # if there is no project that can be selected within the available capital, break
            if not heap:
                break
            # select the project with the maximum profit
            w -= heapq.heappop(heap)
        return w
    

# O(nlogn)
class Solution:
    def findMaximizedCapital(self, k: int, w: int, profits: List[int], capital: List[int]) -> int:
        maxProfit = [] # only projects we can afford
        minCapital = [(c, p) for c,p in zip(capital, profits)]
        heapq.heapify(minCapital)

        for i in range(k):
            while minCapital and minCapital[0][0] <= w:
                c, p = heapq.heappop(minCapital)
                heapq.heappush(maxProfit, -1 * p)
            if not maxProfit:
                break
            w += -1 * heapq.heappop(maxProfit)
        return w