class Solution:
    def quickSort(self, arr):
        if len(arr) < 2:
            return arr

        pivot = arr[0]
        less = [i for i in arr[1:] if i <= pivot]
        greater = [i for i in arr[1:] if i > pivot]

        return self.quickSort(less) + [pivot] + self.quickSort(greater)
    
print(Solution().quickSort([1, 5, 2, 8, 3, 4, 7, 6]))