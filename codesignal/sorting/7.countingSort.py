class Solution:
    def countingSort(self, arr):
        count = [0] * (max(arr) + 1)

        for i in arr:
            count[i] += 1

        arr = []
        for i in range(len(count)):
            arr += [i] * count[i]

        return arr