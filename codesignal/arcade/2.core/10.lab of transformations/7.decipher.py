# Consider the following ciphering algorithm:

# For each character replace it with its code.
# Concatenate all of the obtained numbers.
# Given a ciphered string, return the initial one if it is known that it consists only of lowercase 
# letters.

# Note: here the character's code means its decimal ASCII code, the numerical representation of a 
# character used by most modern programming languages.

# Example

# For cipher = "10197115121", the output should be
# solution(cipher) = "easy".

class Solution:
    def solution(self, cipher):
        r = ''
        i = 0
        while i < len(cipher):
            l = 3 if cipher[i] == '1' else 2
            r += chr(int(cipher[i:i+l]))
            i += l
        return r