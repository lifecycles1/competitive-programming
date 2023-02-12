# an algorithm that checks if a given grid of numbers represents a correct solution to Sudoku

# Example

# For
# grid = [[1, 3, 2, 5, 4, 6, 9, 8, 7],
#         [4, 6, 5, 8, 7, 9, 3, 2, 1],
#         [7, 9, 8, 2, 1, 3, 6, 5, 4],
#         [9, 2, 1, 4, 3, 5, 8, 7, 6],
#         [3, 5, 4, 7, 6, 8, 2, 1, 9],
#         [6, 8, 7, 1, 9, 2, 5, 4, 3],
#         [5, 7, 6, 9, 8, 1, 4, 3, 2],
#         [2, 4, 3, 6, 5, 7, 1, 9, 8],
#         [8, 1, 9, 3, 2, 4, 7, 6, 5]]

# the output should be solution(grid) = true;


def solution(grid):
    # Check rows
    for row in grid:
        seen = set()
        for num in row:
            if num in seen:
                return False
            seen.add(num)
    # Check columns
    for col in zip(*grid):
        seen = set()
        for num in col:
            if num in seen:
                return False
            seen.add(num)
    # Check 3x3 sub-grids
    for i in range(0, 9, 3):
        for j in range(0, 9, 3):
            seen = set()
            for row in range(i, i + 3):
                for col in range(j, j + 3):
                    num = grid[row][col]
                    if num in seen:
                        return False
                    seen.add(num)
    return True



# JavaScript solution

# function solution(grid) {
#   // Check rows
#   for (let row of grid) {
#     let seen = new Set();
#     for (let num of row) {
#       if (seen.has(num)) {
#         return false;
#       }
#       seen.add(num);
#     }
#   }
#   // Check columns
#   for (let i = 0; i < 9; i++) {
#     let seen = new Set();
#     for (let j = 0; j < 9; j++) {
#       let num = grid[j][i];
#       if (seen.has(num)) {
#         return false;
#       }
#       seen.add(num);
#     }
#   }
#   // Check 3x3 sub-grids
#   for (let i = 0; i < 9; i += 3) {
#     for (let j = 0; j < 9; j += 3) {
#       let seen = new Set();
#       for (let row = i; row < i + 3; row++) {
#         for (let col = j; col < j + 3; col++) {
#           let num = grid[row][col];
#           if (seen.has(num)) {
#             return false;
#           }
#           seen.add(num);
#         }
#       }
#     }
#   }
#   return true;
# }
