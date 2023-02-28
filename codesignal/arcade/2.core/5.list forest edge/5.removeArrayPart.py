# Remove a part of a given array between given 0-based indexes l and r (inclusive).

class Solution:
    def removeArrayPart(self, inputArray, l, r):
        return inputArray[:l] + inputArray[r+1:]