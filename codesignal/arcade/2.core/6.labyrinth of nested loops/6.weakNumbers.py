# We define the weakness of number x as the number of positive integers smaller than x that have 
# more divisors than x.

# It follows that the weaker the number, the greater overall weakness it has. For the given 
# integer n, you need to answer two questions:

# what is the weakness of the weakest numbers in the range [1, n]?
# how many numbers in the range [1, n] have this weakness?
# Return the answer as an array of two elements, where the first element is the answer to the 
# first question, and the second element is the answer to the second question.

class Solution:
    def weakNumbers(self, n):
        def s(x):
            return sum(1 for i in range(1, x + 1) if x % i == 0)
        d = {i: s(i) for i in range(1, n + 1)}
        w = {i: sum(1 for j in range(1, i) if d[j] > d[i]) for i in range(1, n + 1)}
        return [max(w.values()), sum(1 for i in w.values() if i == max(w.values()))]