# Given two strings a and b, both consisting only of lowercase English letters, 
# your task is to calculate how many strings equal to a can be constructed using 
# only letters from the string b? Each letter can be used only once and in one string only.

class Solution:
    def stringsConstruction(self, a, b):
        return min(b.count(c)//a.count(c) for c in a)