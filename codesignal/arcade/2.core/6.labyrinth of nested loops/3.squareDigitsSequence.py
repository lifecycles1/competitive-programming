# Consider a sequence of numbers a0, a1, ..., an, in which an element is equal to the sum of 
# squared digits of the previous element. The sequence ends once an element that has already 
# been in the sequence appears again.

# Given the first element a0, find the length of the sequence.

class Solution:
    def squareDigitsSequence(self, a0):
        a = a0
        b = []
        while a not in b:
            b.append(a)
            a = sum([int(i)**2 for i in str(a)])
        return len(b)+1