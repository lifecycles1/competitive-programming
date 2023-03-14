# Given an array of 2k integers (for some integer k), perform the following operations until the 
# array contains only one element:

# On the 1st, 3rd, 5th, etc. iterations (1-based) replace each pair of consecutive elements with their sum;
# On the 2nd, 4th, 6th, etc. iterations replace each pair of consecutive elements with their product.
# After the algorithm has finished, there will be a single element left in the array. Return that element.

class Solution:
    def arrayConversion(self, inputArray):
        isOdd = True
        while len(inputArray) != 1:
            if isOdd:
                inputArray = [inputArray[i] + inputArray[i+1] for i in range(0, len(inputArray), 2)]
            else:
                inputArray = [inputArray[i] * inputArray[i+1] for i in range(0, len(inputArray), 2)]
            isOdd = not isOdd
        return inputArray[0]