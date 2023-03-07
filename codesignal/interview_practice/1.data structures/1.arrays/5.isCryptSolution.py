# A cryptarithm is a mathematical puzzle for which the goal is to find the correspondence between letters 
# and digits, such that the given arithmetic equation consisting of letters holds true when the letters 
# are converted to digits.

# You have an array of strings crypt, the cryptarithm, and an an array containing the mapping of letters 
# and digits, solution. The array crypt will contain three non-empty strings that follow the structure: 
# [word1, word2, word3], which should be interpreted as the word1 + word2 = word3 cryptarithm.

# If crypt, when it is decoded by replacing all of the letters in the cryptarithm with digits using the 
# mapping in solution, becomes a valid arithmetic equation containing no numbers with leading zeroes, 
# the answer is true. If it does not become a valid arithmetic solution, the answer is false.

# Note that number 0 doesn't contain leading zeroes (while for example 00 or 0123 do).

# Example

# For   crypt = ["SEND", "MORE", "MONEY"] and
#       solution = [['O', '0'],
#                   ['M', '1'],
#                   ['Y', '2'],
#                   ['E', '5'],
#                   ['N', '6'],
#                   ['D', '7'],
#                   ['R', '8'],
#                   ['S', '9']]

# the output should be
# solution(crypt, solution) = true.

# When you decrypt "SEND", "MORE", and "MONEY" using the mapping given in crypt, you get 
# 9567 + 1085 = 10652 which is correct and a valid arithmetic equation.


def solution(crypt, solution):
    crypt_s = crypt
    for i in range(0, 3):
        for s in solution:
            crypt_s[i] = crypt_s[i].replace(s[0], s[1])
        
        if crypt_s[i] != '0' and crypt_s[i][0] == '0':
            return False
        
    if int(crypt_s[0]) + int(crypt_s[1]) != int(crypt_s[2]):
        return False
    
    return True



# JS solution

# function solution(crypt, solution) {
#     const [a, b, c] = crypt;
#     const map = {};
#     solution.forEach((item) => map[item[0]] = +item[1])
#     console.log(map)

#     const convert = (n) => {
#         if (!map[n[0]] && n.length > 1) return NaN;
#         return +n.split('').map(l => map[l]).join('')
#     }
    
#     return convert(a) + convert(b) === convert(c);
# }




# JS solution 2

# function solution(crypt, solution) {
#     first = []
#     for (i=0; i<crypt.length; i++) {
#         for (j=0; j<crypt[i].length; j++) {
#             for (m=0; m<solution.length; m++) {
#                 if (crypt[i][j] === solution[m][0]) {
#                     first.push(solution[m][1])
#                 }
#             }
#         }
#     }
#     second = first.splice(crypt[0].length)
#     last = second.splice(crypt[1].length)
#     for (i=0; i<crypt.length; i++) {
#         if (crypt[i].length > 1) {
#             if ((parseInt(first.join("")) + parseInt(second.join(""))) === parseInt(last.join("")) && first[0] != "0" && second[0] != "0") {
#                 return true
#             } else return false
#         } else {
#             if ((parseInt(first.join("")) + parseInt(second.join(""))) === parseInt(last.join(""))) {
#                 return true
#             } else return false
#         }
#     }
# }