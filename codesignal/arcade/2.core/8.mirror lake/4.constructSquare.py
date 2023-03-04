# Given a string consisting of lowercase English letters, find the largest square number which 
# can be obtained by reordering the string's characters and replacing them with any digits you need 
# (leading zeros are not allowed) where same characters always map to the same digits and 
# different characters always map to different digits.

# If there is no solution, return -1.

class Solution:
    def constructSquare(self, s: str) -> int:
        def sortedHistogram(t, base):
            h = [0] * 26
            for x in t:
                h[ord(x) - ord(base)] += 1
            h.sort()
            return h
        
        hs = sortedHistogram(s, 'a')

        hi2 = 10 ** len(s)
        largest = -1
        for i in range(int(10 ** ((len(s) - 1) / 2)), int(hi2 ** 0.5) + 1):
            if hs ==sortedHistogram(str(i * i), '0'):
                largest = i * i
                
        return largest
        