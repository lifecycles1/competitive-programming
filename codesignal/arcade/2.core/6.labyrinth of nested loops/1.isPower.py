# Determine if the given number is a power of some non-negative integer.

class Solution:
    def isPower(self, n):
        if n == 1:
            return True
        for i in range(2, n):
            for j in range(2, n):
                if i ** j == n:
                    return True
        return False