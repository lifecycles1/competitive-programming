# Let's call two integers A and B friends if each integer from the array divisors is either a 
# divisor of both A and B or neither A nor B. If two integers are friends, they are said to be 
# in the same clan. How many clans are the integers from 1 to k, inclusive, broken into?

class Solution:
    def numberOfClans(self, divisors, k):
        return len(set([tuple([x%y==0 for y in divisors]) for x in range(1,k+1)]))