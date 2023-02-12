# Given a string, find the shortest possible string which can be achieved by adding characters to the end of 
# initial string to make it a palindrome.


# Python solution

def solution(st):
    string_list = list(st)
    i = 0
    while string_list != string_list[::-1]:
        string_list.insert(len(st),st[i])
        i += 1
    return "".join(string_list)



# JavaScript recursion solution

# function solution(st) {
#     if (isPalindrome(st))  return st;
#     for (var i = 0; i < st.length; i++) {
#         if (isPalindrome(st.slice(i, st.length))) {
#             return st + Array.from(st.slice(0, i)).reverse().join('');
#         }
#     }
# }

# function isPalindrome(string) {
#     return string == Array.from(string).reverse().join('')
# }

