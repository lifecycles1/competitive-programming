# Some people are standing in a row in a park. There are trees between them which cannot be moved. 
# Your task is to rearrange the people by their heights in a non-descending order without 
# moving the trees. People can be very tall!

# Example

# For a = [-1, 150, 190, 170, -1, -1, 160, 180], the output should be
# solution(a) = [-1, 150, 160, 170, -1, -1, 180, 190].

class Solution:
    def sortByHeight(self, a):
        # find the index of all -1
        index = [i for i, x in enumerate(a) if x == -1]
        # remove all -1
        a = [x for x in a if x != -1]
        # sort the list
        a.sort()
        # insert -1 back to the list
        for i in index:
            a.insert(i, -1)
        return a
    
class Solution:
    def sortByHeight2(self, a):
        for i in range(len(a)):
            for j in range(len(a)):
                if a[i] < a[j] and a[i] != -1 and a[j] != -1:
                    a[i], a[j] = a[j], a[i]
        return a