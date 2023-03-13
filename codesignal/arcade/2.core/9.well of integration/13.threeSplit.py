# You have a long strip of paper with integers written on it in a single line from left to right. 
# You wish to cut the paper into exactly three pieces such that each piece contains at least one 
# integer and the sum of the integers in each piece is the same. You cannot cut through a number, 
# i.e. each initial number will unambiguously belong to one of the pieces after cutting. 
# How many ways can you do it?

# It is guaranteed that the sum of all elements in the array is divisible by 3.

class Solution:
    def threeSplit(self, a):
        summ = 0
        for i in a:
            summ += i
        find = summ // 3

        cut1 = 0
        total = 0
        summ = 0
        for i in range(len(a)-1):
            x = a[i]
            summ += x
            total += cut1 if summ == 2*find else 0
            cut1 += summ == find
        return total