# Given an array of strings, return another array containing all of its longest strings.

class Solution:
    def allLongestStrings(self, inputArray):
        return [x for x in inputArray if len(x) == max([len(y) for y in inputArray])]
    
class Solution:
    def allLongestStrings(self, inputArray):
        r = []
        l = max(inputArray, key=len)
        for s in inputArray:
            if len(s) == len(l):
                r.append(s)
        return r