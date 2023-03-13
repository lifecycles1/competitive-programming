# An alphanumeric ordering of strings is defined as follows: each string is considered as a 
# sequence of tokens, where each token is a letter or a number (as opposed to an isolated digit, as is 
# the case in lexicographic ordering). For example, the tokens of the string "ab01c004" are [a, b, 01, 
# c, 004]. In order to compare two strings, we'll first break them down into tokens and then compare 
# the corresponding pairs of tokens with each other (i.e. compare the first token of the first string 
# with the first token of the second string, etc).

# Here is how tokens are compared:

# If a letter is compared with another letter, the usual alphabetical order applies.
# A number is always considered less than a letter.
# When two numbers are compared, their values are compared. Leading zeros, if any, are ignored.
# If at some point one string has no more tokens left while the other one still does, the one with 
# fewer tokens is considered smaller.

# If the two strings s1 and s2 appear to be equal, consider the smallest index i such that tokens(s1)[i] 
# and tokens(s2)[i] (where tokens(s)[i] is the ith token of string s) differ only by the number of 
# leading zeros. If no such i exists, the strings are indeed equal. Otherwise, the string whose ith 
# token has more leading zeros is considered smaller.

# Here are some examples of comparing strings using alphanumeric ordering.

# "a" < "a1" < "ab"
# "ab42" < "ab000144" < "ab00144" < "ab144" < "ab000144x"
# "x11y012" < "x011y13"
# Your task is to return true if s1 is strictly less than s2, and false otherwise.

class Solution:
    def alphanumericLess(self, s1: str, s2: str) -> bool:
        done = True
        res = self.cmp(s1, s2, done, False)
        if not done:
            done = True
            res = self.cmp(s1, s2, done, True)
        return res
    
    def cmp(self, s1: str, s2: str, done: bool, checkZeroes: bool) -> bool:
        i, j = 0, 0
        while i < len(s1) or j < len(s2):
            if i == len(s1) or j == len(s2):
                return j != len(s2)
            if s1[i].isalpha() or s2[j].isalpha():
                if s1[i] != s2[j]:
                    return s1[i].isdigit() or s1[i] < s2[j]
                i += 1
                j += 1
            else:
                ip, jp = i, j
                n1 = self.parseNum(s1, i)
                n2 = self.parseNum(s2, j)
                if n1 != n2:
                    return n1 < n2
                if checkZeroes and i-ip != j-jp:
                    return i-ip > j-jp
        done = False
        return False
    
    def parseNum(self, s: str, i: int) -> int:
        n = 0
        while i < len(s) and s[i].isdigit():
            n = n*10 + int(s[i])
            i += 1
        return n
