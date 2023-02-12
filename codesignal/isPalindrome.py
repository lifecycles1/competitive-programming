
# Either one of these methods can be used

# Reverse the string and compare to the original

# function isPalindrome(str) {
#     return str === str.split('').reverse().join('');
# }



# Use a for loop to iterate over the string

# function isPalindrome(str) {
#     for (let i = 0; i < str.length / 2; i++) {
#         if (str[i] !== str[str.length - i - 1]) {
#             return false;
#         }
#     }
#     return true;
# }



# Using Recursion

# function isPalindrome(str) {
#     if (str.length === 0 || str.length === 1)
#         return true;
#     if (str[0] === str[str.length - 1])
#         return isPalindrome(str.slice(1, str.length - 1));
#     return false;
# }







