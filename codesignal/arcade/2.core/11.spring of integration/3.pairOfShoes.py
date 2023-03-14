# Yesterday you found some shoes in the back of your closet. Each shoe is described by two values:

# type indicates if it's a left or a right shoe;
# size is the size of the shoe.
# Your task is to check whether it is possible to pair the shoes you found in such a way that each 
# pair consists of a right and a left shoe of an equal size.

# Example

# For

# shoes = [[0, 21], 
#          [1, 23], 
#          [1, 21], 
#          [0, 23]]
# the output should be
# solution(shoes) = true;

class Solution:
    def pairOfShoes(shoes):
        a = []
        b = []
        for s in shoes:
            if s[0] == 0:
                a.append(s[1])
            else:
                b.append(s[1])
        return sorted(a) == sorted(b)