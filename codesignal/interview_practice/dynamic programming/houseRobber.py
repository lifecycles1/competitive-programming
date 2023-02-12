# You are planning to rob houses on a specific street, and you know that every house on the street has a 
# certain amount of money hidden. The only thing stopping you from robbing all of them in one night is 
# that adjacent houses on the street have a connected security system. The system will automatically 
# trigger an alarm if two adjacent houses are broken into on the same night.

# Given a list of non-negative integers nums representing the amount of money hidden in each house, 
# determine the maximum amount of money you can rob in one night without triggering an alarm.

# Example

# For nums = [1, 1, 1], the output should be
# solution(nums) = 2.

def solution(nums):
    prev_max = 0
    prev_prev_max = 0
    for n in nums:
        prev_prev_max, prev_max = prev_max, max(prev_prev_max + n, prev_max)
    return prev_max

# Python solution 2

# def solution(nums):
#     # Edge case: if the input list is empty, return 0
#     if not nums:
#         return 0
    
#     # Edge case: if the input list has only one element, return that element
#     if len(nums) == 1:
#         return nums[0]
    
#     # Create an array to store the maximum amount of money that can be robbed
#     # at each house
#     max_money = [0] * len(nums)
    
#     # Set the base cases
#     max_money[0] = nums[0]
#     max_money[1] = max(nums[0], nums[1])
    
#     # Calculate the maximum amount of money that can be robbed at each house
#     # starting from the base cases
#     for i in range(2, len(nums)):
#         max_money[i] = max(max_money[i-1], max_money[i-2] + nums[i])
    
#     # Return the maximum amount of money that can be robbed
#     return max_money[-1]


# JS solution

# solution = a => {
#     x = y = 0
#     for (k of a)
#         y = Math.max(x + k, x = y)
#     return y
# }


# JS solution 2

# function solution(nums) {
#   // Edge case: if the input array is empty, return 0
#   if (nums.length === 0) {
#     return 0;
#   }

#   // Edge case: if the input array has only one element, return that element
#   if (nums.length === 1) {
#     return nums[0];
#   }

#   // Divide the input array into two halves
#   let mid = Math.floor(nums.length / 2);
#   let left = nums.slice(0, mid);
#   let right = nums.slice(mid);

#   // Recursively calculate the maximum amount of money that can be robbed
#   // from the left half of the input array
#   console.log(`Calculating maxLeft for array: ${left}`);
#   let maxLeft = solution(left);
#   console.log(`maxLeft for array ${left}: ${maxLeft}`);

#   // Recursively calculate the maximum amount of money that can be robbed
#   // from the right half of the input array
#   console.log(`Calculating maxRight for array: ${right}`);
#   let maxRight = solution(right);
#   console.log(`maxRight for array ${right}: ${maxRight}`);

#   // Calculate the maximum amount of money that can be robbed from the current
#   // house and the previous two houses
#   let maxCurrent = nums[mid] + nums[mid - 1] + nums[mid - 2];

#   // Return the maximum of the maximum amount of money that can be robbed from
#   // the left and right halves of the input array, and the maximum amount of
#   // money that can be robbed from the current house and the previous two houses
#   return Math.max(maxLeft, maxRight, maxCurrent);
# }

# solution(nums);
