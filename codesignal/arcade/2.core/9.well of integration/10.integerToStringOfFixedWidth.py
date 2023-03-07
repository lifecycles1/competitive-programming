# Given a positive integer number and a certain length, we need to modify the given number to have 
# a specified length. We are allowed to do that either by cutting out leading digits 
# (if the number needs to be shortened) or by adding 0s in front of the original number.

class Solution:
    def integerToStringOfFixedWidth(self, number, width):
        return str(number).zfill(width)[-width:]