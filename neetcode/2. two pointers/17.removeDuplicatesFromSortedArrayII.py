# Return k after placing the final result in the first k slots of nums.

# Do not allocate extra space for another array. You must do this by modifying the input array 
# in-place with O(1) extra memory

from typing import List

class Solution:
    def removeDuplicates(self, nums: List[int]) -> int:
        if not nums:
            return 0
        i = 0
        for n in nums:
            if i < 2 or n > nums[i-2]:
                nums[i] = n
                i += 1
        return i
    
    
# two pointers solution
class Solution:
    def removeDuplicates(self, nums: List[int]) -> int:
        l, r = 0, 0
        while r < len(nums):
            count = 1
            while r+1 < len(nums) and nums[r] == nums[r+1]:
                r += 1
                count += 1
            for i in range (min(2, count)):
                nums[l] = nums[r]
                l += 1
            r += 1
        return l