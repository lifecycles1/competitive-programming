# Proper nouns always begin with a capital letter, followed by small letters.

# Correct a given proper noun so that it fits this statement.

class Solution:
    def properNounCorrection(inputString):
        return inputString[0].upper() + inputString[1:].lower()