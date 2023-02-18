# A company is planning to interview 2n people. Given the array costs where 
# costs[i] = [aCosti, bCosti], the cost of flying the ith person to city a is aCosti, 
# and the cost of flying the ith person to city b is bCosti.

# Return the minimum cost to fly every person to a city such that exactly n people 
# arrive in each city.

from typing import List

class Solution:
    def twoCitySchedCost(self, costs: List[List[int]]) -> int:
        diffs = []
        for c1, c2 in costs:
            diffs.append([c2 - c1, c1, c2])
        diffs.sort()
        res = 0
        for i in range(len(diffs)):
            if i < len(diffs) / 2:
                res += diffs[i][2]
            else:
                res += diffs[i][1]
        return res