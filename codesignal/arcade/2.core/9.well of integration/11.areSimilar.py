# Two arrays are called similar if one can be obtained from another by swapping at most one pair 
# of elements in one of the arrays.

# Given two arrays a and b, check whether they are similar.

class Solution:
    def areSimilar(self, a, b):
        return sorted(a) == sorted(b) and sum(x != y for x, y in zip(a, b)) < 3
    
class Solution:
    def areSimilar(self, a, b):
        count = 0
        for i in range(len(a)):
          if a[i] != b[i]:
            count += 1
        if count > 2:
          return False
        a = sorted(a)
        b = sorted(b)
        for i in range(len(a)):
          if a[i] != b[i]:
            return False
        return True