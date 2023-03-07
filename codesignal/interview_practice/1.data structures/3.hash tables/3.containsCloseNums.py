# Given an array of integers nums and an integer k, determine whether there are two distinct 
# indices i and j in the array where nums[i] = nums[j] and the absolute difference between i and j 
# is less than or equal to k.

class Solution:
    def containsCloseNums(self, nums, k):
        # create a dictionary to store the index of each number
        # if the number is already in the dictionary, check if the difference between the current index and the index in the dictionary is less than or equal to k
        # if it is, return True
        # if not, update the index in the dictionary to the current index
        # if the number is not in the dictionary, add it to the dictionary with the current index
        # if the loop ends, return False
        d = {}
        for i in range(len(nums)):
            if nums[i] in d:
                if i - d[nums[i]] <= k:
                    return True
                else:
                    d[nums[i]] = i
            else:
                d[nums[i]] = i
        return False