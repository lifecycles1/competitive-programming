# Consider a string containing only letters and whitespaces. It is allowed to replace some 
# (possibly, none) whitespaces with newline symbols to obtain a multiline text. Call a multiline 
# text beautiful if and only if each of its lines (i.e. substrings delimited by a newline character) 
# contains an equal number of characters (only letters and whitespaces should be taken into account 
# when counting the total while newline characters shouldn't). Call the length of the line the text width.

# Given a string and some integers l and r (l ≤ r), check if it's possible to obtain a beautiful text 
# from the string with a text width that's within the range [l, r].

class Solution:
    def beautifulText(self, inputString, l, r):
        for w in range(l, r+1):
            i = w
            while i < len(inputString):
                if inputString[i] != ' ':
                    break
                i += w+1
            if i == len(inputString):
                return True
        return False