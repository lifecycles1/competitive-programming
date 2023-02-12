# This approach uses dynamic programming to determine whether the given string s is a k-palindrome.

# This approach has a time complexity of O(n^2) and a space complexity of O(n^2) as well

# function isKPalindrome(s, k) {
#     // Get the length of the input string
#     let n = s.length;

#     // Create a 2D DP array with n rows and n columns, initially filled with 0's
#     let dp = new Array(n);
#     for (let i = 0; i < n; i++) {
#         dp[i] = new Array(n).fill(0);
#     }

#     // Iterate through the string in reverse order
#     for (let i = n - 1; i >= 0; i--) {
#         for (let j = i; j < n; j++) {
#             // If the current characters at index i and j are the same, 
#             // the number of characters that need to be removed is the same as for the substring s[i+1...j-1]
#             if (s[i] == s[j]) {
#                 dp[i][j] = i === j ? 0 : dp[i + 1][j - 1];
#             } else {
#                 // If the current characters at index i and j are different, 
#                 // the number of characters that need to be removed is 1 + the minimum number of characters that need to be removed from the substring s[i+1...j] or s[i...j-1]
#                 dp[i][j] = Math.min(dp[i + 1][j], dp[i][j - 1]) + 1;
#             }
#         }
#     }

#     // Check if the number of characters that need to be removed is less than or equal to k,
#     // and return true if it is, indicating that the string is a k-palindrome
#     return dp[0][n - 1] <= k;
# }