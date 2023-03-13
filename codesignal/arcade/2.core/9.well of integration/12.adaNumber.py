# Consider two following representations of a non-negative integer:

# A simple decimal integer, constructed of a non-empty sequence of digits from 0 to 9;
# An integer with at least one digit in a base from 2 to 16 (inclusive), 
# enclosed between # characters, and preceded by the base, which can only be a number between 
# 2 and 16 in the first representation. For digits from 10 to 15 characters a, b, ..., f 
# and A, B, ..., F are used.
# Additionally, both representations may contain underscore (_) characters; they are used only 
# as separators for improving legibility of numbers and can be ignored while processing a number.

# Your task is to determine whether the given string is a valid integer representation.

class Solution:
    def adaNumber(self, line):
        line = line.replace("_", "")
        if "#" not in line:
            try: int(line)
            except: return False
        else:
            try: 
                n = int(line[line.find("#") + 1:line.rfind("#")], int(line[:line.find("#")]))
                if int(line[:line.find("#")]) > 16 or int(line[:line.find("#")]) < 2: return False
            except: return False
        return True