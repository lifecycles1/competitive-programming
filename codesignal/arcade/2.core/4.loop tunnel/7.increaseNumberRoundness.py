# Define an integer's roundness as the number of trailing zeroes in it.

# Given an integer n, check if it's possible to increase n's roundness by swapping some 
# pair of its digits.

class Solution:
    def increaseNumberRoundness(n: int) -> bool:
        l = 0
        while n:
            if l and n % 10 == 0:
                return True
            l = n % 10
            n //= 10
        return False