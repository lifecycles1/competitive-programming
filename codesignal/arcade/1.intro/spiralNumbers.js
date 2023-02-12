// Construct a square matrix with a size N × N containing integers from 1 to N * N in a spiral order,
// starting from top-left and in clockwise direction.

// Example

// For n = 3, the output should be

// solution(n) = [[1, 2, 3],
//                [8, 9, 4],
//                [7, 6, 5]]

function solution(n) {
  let matrix = [];
  for (let i = 0; i < n; i++) {
    matrix[i] = new Array(n);
  }
  let count = 1;
  let startRow = 0;
  let endRow = n - 1;
  let startCol = 0;
  let endCol = n - 1;
  while (startRow <= endRow && startCol <= endCol) {
    // fill the top row from left to right
    for (let i = startCol; i <= endCol; i++) {
      matrix[startRow][i] = count;
      count++;
    }
    startRow++;
    // fill the rightmost column from top to bottom
    for (let i = startRow; i <= endRow; i++) {
      matrix[i][endCol] = count;
      count++;
    }
    endCol--;
    // fill the bottom row from right to left
    if (startRow <= endRow) {
      for (let i = endCol; i >= startCol; i--) {
        matrix[endRow][i] = count;
        count++;
      }
      endRow--;
    }
    // fill the leftmost column from bottom to top
    if (startCol <= endCol) {
      for (let i = endRow; i >= startRow; i--) {
        matrix[i][startCol] = count;
        count++;
      }
      startCol++;
    }
  }
  return matrix;
}

// The first two for-loops inside the while loop explained :

// loop 1
// this for loop is iterating through the top row of the matrix, starting from the leftmost column (startCol)
// to the rightmost column (endCol). It's using the startCol and endCol variables to keep track of the left and
// right boundaries of the current sub-matrix that is being filled. The startCol variable is initially set to 0,
// and the endCol variable is set to n-1 where n is the size of the matrix. This means that the for loop is
// iterating over all the columns of the top row, from the first column to the last column. The startRow variable
// is incremented after the for loop, this is to move the top boundary of the sub-matrix one row down, and now
// the new top row will be the row that follows the current top row, so it's ready for the next iteration. In the
// next iteration, the startRow variable has been incremented, so the new top row will be the next row, and the
// for loop will be iterating over the rightmost column, from top to bottom, and so on. It's important to note
// that this for loop is only running once, since the variable startRow is incremented, and it's only running
// until the endCol to fill the top row, and not the rest of the matrix.

// loop 2

// The next for loop that runs is the one that fills the rightmost column of the matrix, starting from the top row
// (startRow) to the bottom row (endRow). It's using the startRow and endRow variables to keep track of the top and
// bottom boundaries of the current sub-matrix that is being filled. The startRow variable has been incremented in
// the previous iteration, so the new top row will be the next row, and the endRow variable is set to n-1 where n is
// the size of the matrix. This means that the for loop is iterating over all the rows of the rightmost column, from
// the first row to the last row. The endCol variable is decremented after the for loop, this is to move the right
// boundary of the sub-matrix one column left, and now the new rightmost column will be the column that precedes the
// current rightmost column, so it's ready for the next iteration. In the next iteration, the endCol variable has
// been decremented, so the new rightmost column will be the next column, and the for loop will be iterating over
// the bottom row, from right to left, and so on. It's important to note that this for loop is only running once,
// since the variable endCol is decremented, and it's only running until the endRow to fill the rightmost column,
// and not the rest of the matrix.

// the same logic applies to the other 2 for-loops that are inside the while loop.
// they will fill the bottom row and the last one will fill the leftmost column

// Python solution

// def solution(n, m=0, s=1):
//     if m==0: m=n
//     if n==1==m:
//         return [[s]]

//     #Calculate spiral numbers without first row
//     S=solution(m-1, n, s+n)

//     #Create first row and add the transpose of the rest
//     return [[i for i in range(s,s+n)]] + [list(x) for x in zip(*S[::-1])]
