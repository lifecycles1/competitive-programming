class Solution:
    def mergeSort(self, arr):
        if len(arr) == 1:
            return arr

        middle = len(arr) // 2
        left = arr[:middle]
        right = arr[middle:]

        return self.merge(self.mergeSort(left), self.mergeSort(right))
    
    def merge(self, left, right):
        result = []
        leftIndex = 0
        rightIndex = 0

        while leftIndex < len(left) and rightIndex < len(right):
            if left[leftIndex] < right[rightIndex]:
                result.append(left[leftIndex])
                leftIndex += 1
            else:
                result.append(right[rightIndex])
                rightIndex += 1

        return result + left[leftIndex:] + right[rightIndex:]
    
print(Solution().mergeSort([1, 5, 2, 8, 3, 4, 7, 6]))

from typing import List

# quicker solution
class Solution:
    def sortArray(self, nums: List[int]) -> List[int]:
        def merge(arr, L, M, R):
            left, right = arr[L:M+1], arr[M+1:R+1]
            i, j, k = L, 0, 0
            while j < len(left) and k < len(right):
                if left[j] <= right[k]:
                    arr[i] = left[j]
                    j += 1
                else:
                    arr[i] = right[k]
                    k += 1
                i += 1
            while j < len(left):
                nums[i] = right[k]
                k += 1
                i += 1

        def mergeSort(arr, l, r):
            if l == r:
                return arr
            m = (l + r) // 2
            mergeSort(arr, l, m)
            mergeSort(arr, m + 1, r)
            merge(arr, l, m, r)
            return arr
        
        return mergeSort(nums, 0, len(nums) - 1)