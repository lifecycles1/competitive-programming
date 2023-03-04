# Check whether the given string is a subsequence of the plaintext alphabet.

class Solution:
    def alphabetSubsequence(s):
        return "".join(sorted(s)) == s and len(set(s)) == len(s)
    
class Solution:
    def alphabetSubsequence(s):
          for i in range(1, len(s)):
            if s[i] <= s[i-1]:
              return False
          return True