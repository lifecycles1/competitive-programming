# You are given a boolean matrix field representing the distribution of bombs in the rectangular field. 
# You are also given integers x and y, representing the coordinates of the player's first clicked 
# cell - x represents the row index, and y represents the column index, both of which are 0-based.

# Your task is to return an integer matrix of the same dimensions as field, representing the resulting 
# field after applying this click. If a cell remains concealed, the corresponding element should have a 
# value of -1.

# It is guaranteed that the clicked cell does not contain a mine.

# Example

# For
# field = [[false, true, true],
#          [true, false, true],
#          [false, false, true]]

# x = 1, and y = 1, the output should be

# solution(field, x, y) = [[-1, -1, -1],
#                          [-1, 5, -1],
#                          [-1, -1, -1]]



# The function below uses depth first search algorithm to traverse the field and check the number of bombs 
# around the clicked cell and fill the result array accordingly.
# The function click() takes a 2D boolean matrix and the coordinates of the first click and returns a 
# matrix filled with numbers of bombs surrounding the cell or -1 if the cell is not yet visited.
# The function dfs() takes the field, the current cell, and the result matrix, and traverse the 
# surrounding cells of the current cell and count the number of bombs around it.


# function solution(field, x, y) {
#     // Initialize the result matrix with all -1 values
#     var rows = field.length;
#     var cols = field[0].length;
#     var result = new Array(rows);
#     for (var i = 0; i < rows; i++) {
#         result[i] = new Array(cols);
#         for (var j = 0; j < cols; j++) {
#             result[i][j] = -1;
#         }
#     }
#     // Perform the depth first search to traverse the field
#     dfs(field, x, y, result);
#     return result;
# }

# function dfs(field, x, y, result) {
#     // Base case: if the current cell is out of bounds or has already been visited, return
#     if (x < 0 || x >= field.length || y < 0 || y >= field[0].length || result[x][y] !== -1) {
#         return;
#     }
#     // Count the number of bombs around the current cell
#     var count = 0;
#     for (var dx = -1; dx <= 1; dx++) {
#         for (var dy = -1; dy <= 1; dy++) {
#             var nx = x + dx;
#             var ny = y + dy;
#             if (nx >= 0 && nx < field.length && ny >= 0 && ny < field[0].length && field[nx][ny]) {
#                 count++;
#             }
#         }
#     }
#     // Assign the number of bombs around the current cell to the result matrix
#     result[x][y] = count;
#     // If the current cell has no bombs around, recursively call dfs on all 8 surrounding cells
#     if (count === 0) {
#         for (var dx = -1; dx <= 1; dx++) {
#             for (var dy = -1; dy <= 1; dy++) {
#                 dfs(field, x + dx, y + dy, result);
#             }
#         }
#     }
# }