// Given a position of a knight on the standard chessboard,
// find the number of different moves the knight can perform.

function solution(cell) {
  const chessBoard = [
    [], // chessboard starts from 1 not 0 like the array structure in most languages so we can have a blank filler unless we want to subtract 1 from the row number every time in the result as so: chessBoard[cell[1] -1][x]
    [2, 3, 4, 4, 4, 4, 3, 2], // and these are all the possible moves a knight can make from that position
    [3, 4, 6, 6, 6, 6, 4, 3],
    [4, 6, 8, 8, 8, 8, 6, 4],
    [4, 6, 8, 8, 8, 8, 6, 4],
    [4, 6, 8, 8, 8, 8, 6, 4],
    [4, 6, 8, 8, 8, 8, 6, 4],
    [3, 4, 6, 6, 6, 6, 4, 3],
    [2, 3, 4, 4, 4, 4, 3, 2],
  ];

  const x = cell[0].charCodeAt() - 97; // if cell is "c2" then cell[0] = "c".charCodeAt() = 99 and 99 - 97 = 2. So x = 2. This is the column number of the cell in the array structure of the chessboard. We subtract by 97 because 97 is letter "a" (the beginning from left to right on the board)
  return chessBoard[cell[1]][x];
}
