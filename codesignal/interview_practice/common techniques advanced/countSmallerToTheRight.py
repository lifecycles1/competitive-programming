# You have array of integers nums and you need to build a new counts array. In the new counts array, counts[i]
#  is the number of smaller elements to the right of nums[i]. You're asked to find not the counts array, but 
# the sum of its elements.

# Example

# For nums = [3, 8, 4, 1], the output should be
# solution(nums) = 4.

# To the right of 3: there is 1 smaller element (1).
# To the right of 8: there are 2 smaller elements (4 and 1).
# To the right of 4: there is 1 smaller element (1).
# To the right of 1: there are 0 smaller elements.
# The resulting array is [1, 2, 1, 0], and the sum of its elements is 1 + 2 + 1 + 0 = 4.




# JavaScript solution

# This solution is using a queue and the binary search algorithm.

# function solution(nums) {
#     let queue = [];
#     let count = 0;

#     while (nums.length > 0) {
#         let top = nums.pop();
        
#         // find index of top
#         let index = binarySearch(queue, top);
        
#         // index of top means number of elements are smaller than top
#         count += index;
        
#         // add top to queue
#         queue.splice(index, 0, top);
#     }

#     return count;
# }

# // find index in array to insert value
# // to maintain a sorted array
# function binarySearch(array, value) {
#     let low = 0,
#         high = array.length;

#     while (low < high) {
#         let mid = (low + high) >>> 1;
#         if (array[mid] < value){ 
#             low = mid + 1
#         }
#         else high = mid;
#     }
#     return low;
# }