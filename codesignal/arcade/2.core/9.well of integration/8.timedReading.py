# Timed Reading is an educational tool used in many schools to improve and advance reading skills. 
# A young elementary student has just finished his very first timed reading exercise. 
# Unfortunately he's not a very good reader yet, so whenever he encountered a word longer than 
# maxLength, he simply skipped it and read on.

# Help the teacher figure out how many words the boy has read by calculating the number of words 
# in the text he has read, no longer than maxLength.
# Formally, a word is a substring consisting of English letters, such that characters to the left 
# of the leftmost letter and to the right of the rightmost letter are not letters.

import re
import string

class Solution:
    def timedReading(self, maxLength, text):
        return sum([1 for x in re.findall(r'[a-zA-Z]+',text) if len(x)<=maxLength])
    
    
class Solution:
    def timedReading(self, maxLength, text):
        # 1. Replace non-alphabetic characters with spaces
        filtered_text = ""
        for i in text:
            if i in string.ascii_letters:
                filtered_text += i
            else:
                filtered_text += " "
        
        # 2. Split the filtered text into words
        words = filtered_text.split()

        # 3. Count the number of words that are shorter than or equal to maxLength
        count = 0
        for j in words:
            if len(j) <= maxLength:
                count += 1
        
        # 4. Return the count
        return count