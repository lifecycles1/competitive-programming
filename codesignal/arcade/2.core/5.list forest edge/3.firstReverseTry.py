# Given an array arr, swap its first and last elements and return the resulting array.

class Solution:
    def firstReverseTry(self, arr):
        if len(arr) > 1:
            arr[0], arr[-1] = arr[-1], arr[0]
        return arr