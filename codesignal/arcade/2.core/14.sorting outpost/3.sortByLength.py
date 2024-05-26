# Given an array of strings, sort them in the order of increasing lengths. 
# If two strings have the same length, their relative order must be the same as in the initial array.

class Solution:
    def sortByLength(self, inputArray):
        return sorted(inputArray, key=len)
    
class Solution:
    def sortByLength(self, inputArray):
        # implement insertion sort algorithm
        for i in range(1, len(inputArray)):
            key = inputArray[i]
            j = i - 1
            while j >= 0 and len(inputArray[j]) > len(key):
                inputArray[j + 1] = inputArray[j]
                j -= 1
            inputArray[j + 1] = key
        return inputArray