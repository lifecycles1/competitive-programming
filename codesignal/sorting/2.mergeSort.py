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