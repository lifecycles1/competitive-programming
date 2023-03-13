# You've intercepted an encrypted message, and you are really curious about its contents. 
# You were able to find out that the message initially contained only lowercase English letters, 
# and was encrypted with the following cipher:

# Let all letters from 'a' to 'z' correspond to the numbers from 0 to 25, respectively.
# The number corresponding to the ith letter of the encrypted message is then equal to the sum 
# of numbers corresponding to the first i letters of the initial unencrypted message modulo 26.
# Now that you know how the message was encrypted, implement the algorithm to decipher it.

class Solution:
    def cipher26(self, message):
        prev_number = 0
        result = ""
        for char in message:
            # Find what was needed to be added to the previous character number
            # to get the value of the current ciphered character. Add 26 to the
            # current number so that we can substract the previous one safely.
            cur_number = ord(char) - ord('a') + 26
            # After substracting the previous one, just do modulus 26 again.
            orig_char = chr((cur_number - prev_number) % 26 + ord('a'))
            # After finding the original character, keep appending it to result.
            result += orig_char
            # Keep storing only the previous character number.
            prev_number = ord(char) - ord('a')

        return result