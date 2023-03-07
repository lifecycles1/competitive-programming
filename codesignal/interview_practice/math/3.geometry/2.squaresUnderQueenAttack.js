// Note: Write a solution with O(queries.length + queens.length + n) complexity and
// O(queries.length) additional memory, since this is what you would be asked to do during a
// real interview.

// In chess, queens can move any number of squares vertically, horizontally, or diagonally.
// You have an n × n chessboard with some queens on it. You are given several queries, each of
// which represents one square on the chessboard. For each query square, determine whether it
// can be attacked by a queen or not.

class Solution {
  squaresUnderQueenAttack(n, queens, queries) {
    rows = new Set();
    cols = new Set();
    diag1 = new Set();
    diag2 = new Set();

    for (let i = 0; i < queens.length; i++) {
      let [row, col] = queens[i];
      rows.add(row);
      cols.add(col);
      diag1.add(row + col);
      diag2.add(row - col);
    }

    let result = [];
    for (let i = 0; i < queries.length; i++) {
      let [row, col] = queries[i];
      if (rows.has(row) || cols.has(col) || diag1.has(row + col) || diag2.has(row - col)) {
        result.push(true);
      } else {
        result.push(false);
      }
    }
    return result;
  }
}
