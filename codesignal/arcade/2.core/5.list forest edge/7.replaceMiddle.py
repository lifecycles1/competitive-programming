# Given array arr, your task is to find its middle, and, if it consists of two elements, 
# replace those elements with the value of middle. Return the resulting array as the answer.

class Solution:
    def replaceMiddle(self, arr):
        if len(arr) % 2 == 0:
            arr[int(len(arr)/2)] = arr[int(len(arr)/2)-1] + arr[int(len(arr)/2)]
            arr.pop(int(len(arr)/2)-1)
        return arr