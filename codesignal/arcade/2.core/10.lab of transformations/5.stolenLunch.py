# When you recently visited your little nephew, he told you a sad story: there's a bully at school 
# who steals his lunch every day, and locks it away in his locker. He also leaves a note with a strange, 
# coded message. Your nephew gave you one of the notes in hope that you can decipher it for him. 
# And you did: it looks like all the digits in it are replaced with letters and vice versa. 
# Digit 0 is replaced with 'a', 1 is replaced with 'b' and so on, with digit 9 replaced by 'j'.

# The note is different every day, so you decide to write a function that will decipher it for 
# your nephew on an ongoing basis.

class Solution:
    def stolenLunch(self, note):
        cipher = {
            '0':'a','a':'0',
            '1':'b','b':'1',
            '2':'c','c':'2',
            '3':'d','d':'3',
            '4':'e','e':'4',
            '5':'f','f':'5',
            '6':'g','g':'6',
            '7':'h','h':'7',
            '8':'i','i':'8',
            '9':'j','j':'9'
        }
        result = ''
        for c in note:
            if c in cipher:
                c = cipher[c]
            result += c
        return result