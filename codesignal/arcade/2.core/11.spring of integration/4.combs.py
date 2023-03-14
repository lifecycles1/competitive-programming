# Miss X has only two combs in her possession, both of which are old and miss a tooth or two. 
# She also has many purses of different length, in which she carries the combs. 
# The only way they fit is horizontally and without overlapping. Given teeth' positions on both combs, 
# find the minimum length of the purse she needs to take them with her.

# It is guaranteed that there is at least one tooth at each end of the comb.
# It is also guaranteed that the total length of two strings is smaller than 32.
# Note, that the combs can not be rotated/reversed.

# Example

# For comb1 = "*..*" and comb2 = "*.*", the output should be
# solution(comb1, comb2) = 5.

# A comb is represented as a string. If there is an asterisk ('*') in the ith position, there is a 
# tooth there. Otherwise there is a dot ('.'), which means there is a missing tooth on the comb.

class Solution:
    def solution(comb1, comb2):
        from itertools import zip_longest
        b1 = ''.join(['0' if x == '.' else '1' for x in comb1])
        b2 = ''.join(['0' if x == '.' else '1' for x in comb2])
        b1 = '0' * len(b2) + b1
        r = []
        for i in range(len(b1)):
            x = b1[:i]
            for a, b in zip_longest(b1[i:], b2, fillvalue='0'):
                x += str(int(a) + int(b))
            if not '2' in x:
                r.append(x.strip('0'))
        return len(sorted(r, key=len)[0])