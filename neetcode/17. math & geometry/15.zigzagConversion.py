# The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: 
# (you may want to display this pattern in a fixed font for better legibility)

# P   A   H   N
# A P L S I I G
# Y   I   R

# And then read line by line: "PAHNAPLSIIGYIR"

# Write the code that will take a string and make this conversion given a number of rows:

class Solution:
    def convert(self, s: str, numRows: int) -> str:
        if numRows == 1:
            return s
        rows = [''] * numRows
        row = 0
        goingDown = False
        for c in s:
            rows[row] += c
            if row == 0 or row == numRows - 1:
                goingDown = not goingDown
            row += 1 if goingDown else -1
        return ''.join(rows)