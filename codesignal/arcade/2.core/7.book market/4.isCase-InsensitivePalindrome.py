# Given a string, check if it can become a palindrome through a case change of some 
# (possibly, none) letters

class Solution:
    def isCaseInsensitivePalindrome(self, inputString):
        return inputString.lower() == inputString.lower()[::-1]