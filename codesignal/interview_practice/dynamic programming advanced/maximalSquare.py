# You have a 2D binary matrix that's filled with 0s and 1s. In the matrix, find the largest square that 
# contains only 1s and return its area.

# Example

# For

# matrix = [
#     ['1', '0', '1', '1', '1'],
#     ['1', '0', '1', '1', '1'],
#     ['1', '1', '1', '1', '1'],
#     ['1', '0', '0', '1', '0'],
#     ['1', '0', '0', '1', '0']
# ]

# the output should be
# solution(matrix) = 9.



# function solution(matrix) {
#     let maxSide = 0
    
#     matrix = matrix.map(row => row.map(col => parseInt(col,10)))
#     const dp = matrix.map((row) => row.slice())
    
#     for (let i = 0; i < matrix.length; i++){
#         for (let j = 0; j < matrix[i].length; j++){
#             if (matrix[i][j] === 1) {
#                 if (i > 0 && j > 0) {
#                     dp[i][j] = Math.min(dp[i-1][j], dp[i][j-1], dp[i-1][j-1]) + 1;
#                 }
#                 maxSide = Math.max(maxSide, dp[i][j]);
#             }
#         }
#     }
#     return maxSide * maxSide;
# }
