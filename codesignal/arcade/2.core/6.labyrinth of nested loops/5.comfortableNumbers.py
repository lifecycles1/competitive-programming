# Let's say that number a feels comfortable with number b if a ≠ b and b lies in 
# the segment [a - s(a), a + s(a)], where s(x) is the sum of x's digits.

# How many pairs (a, b) are there, such that a < b, both a and b lie on the segment [l, r], 
# and each number feels comfortable with the other (so a feels comfortable with b and b feels 
# comfortable with a)?

class Solution:
    def comfortableNumbers(self, l, r):
        def s(x):
            return sum(int(i) for i in str(x))
        return sum(1 for a in range(l, r + 1) for b in range(a + 1, r + 1) if a - s(a) <= b <= a + s(a) and b - s(b) <= a <= b + s(b))