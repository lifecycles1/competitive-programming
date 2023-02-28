# Find the number of ways to express n as sum of some (at least two) consecutive positive integers.

class Solution:
    def isSumOfConsecutive2(self, n):
        count = 0
        for i in range(1, n):
            sum = 0
            for j in range(i, n):
                sum += j
                if sum == n:
                    count += 1
                    break
                elif sum > n:
                    break
        return count