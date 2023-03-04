# A ciphertext alphabet is obtained from the plaintext alphabet by means of rearranging some 
# characters. For example "bacdef...xyz" will be a simple ciphertext alphabet where a and b 
# are rearranged.

# A substitution cipher is a method of encoding where each letter of the plaintext alphabet is 
# replaced with the corresponding (i.e. having the same index) letter of some ciphertext alphabet.

# Given two strings, check whether it is possible to obtain them from each other using some 
# (possibly, different) substitution ciphers.

class Solution:
    def isSubstitutionCipher(self, string1, string2):
        return len(set(zip(string1,string2)))==len(set(string1))==len(set(string2))