# Determine whether the given string can be obtained by one concatenation of some string to itself.

class Solution:
    def isTandemRepeat(self, inputString):
        return inputString[:len(inputString)//2] * 2 == inputString