# You are given two strings s and t of the same length, consisting of uppercase English letters. 
# Your task is to find the minimum number of "replacement operations" needed to get some anagram 
# of the string t from the string s. A replacement operation is performed by picking exactly one 
# character from the string s and replacing it by some other character.

from collections import Counter

class Solution:
    def createAnagram(self, s, t):
        return sum((Counter(s)-Counter(t)).values())
    

class Solution:
    def createAnagram(self, s, t):
        return sum(max(s.count(c)-t.count(c),0) for c in set(s))
    
class Solution:
    def createAnagram(self, s, t):
        s = list(s)
        for i in t:
            if i in s:
                s.remove(i)
        return len(s)