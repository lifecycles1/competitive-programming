# Given an array of integers, replace all the occurrences of elemToReplace with substitutionElem.

class Solution:
    def arrayReplace(self, inputArray, elemToReplace, substitutionElem):
        return [substitutionElem if i == elemToReplace else i for i in inputArray]