# You're given a substring s of some cyclic string. What's the length of the smallest possible string 
# that can be concatenated to itself many times to obtain this cyclic string?

# Example

# For s = "cabca", the output should be
# solution(s) = 3.

# "cabca" is a substring of a cycle string "abcabcabcabc..." that can be obtained by concatenating 
# "abc" to itself. Thus, the answer is 3.

class Solution:
    def solution(s):
        c = 1
        while (s[:c]*len(s))[:len(s)]!=s: 
            c += 1
        return c