// You have a chessboard with n rows and m columns. The knight is placed on the (x, y) cell (0-indexed).
// Find the probability that the knight stays on the board after performing the usual knight move steps times
// randomly. If the knight gets moved off of the board, it can't return to the board again.
// For example, after the move (0, 0) - (-1, -2), it's impossible for the knight to return on the board by
// performing the move (-1, -2) - (0, 0).

// Example

// For n = 8, m = 8, steps = 2, x = 4, and y = 4, the output should be
// solution(n, m, steps, x, y) = 0.875.

function solution(n, m, steps, x, y) {
  // Initialize dp array, a 2D array of size n*m, filled with 0
  let dp = new Array(n);
  for (let i = 0; i < n; i++) {
    dp[i] = new Array(m).fill(0);
  }
  dp[x][y] = 1; // Set the starting cell (x, y) to have a probability of 1

  // Perform steps
  for (let step = 0; step < steps; step++) {
    let newDp = new Array(n); // Create new 2D dp array to store new probabilities
    for (let i = 0; i < n; i++) {
      newDp[i] = new Array(m).fill(0); // fill it with 0
    }
    // Iterate through all cells in the board
    for (let i = 0; i < n; i++) {
      for (let j = 0; j < m; j++) {
        // Knight moves
        // Check if the current cell can perform 8 different valid knight moves (if still on board)
        // If it can, add 1/8th of its probability to the new cell
        if (i - 2 >= 0 && j - 1 >= 0) newDp[i - 2][j - 1] += dp[i][j] / 8; // move up 2 and left 1
        if (i - 2 >= 0 && j + 1 < m) newDp[i - 2][j + 1] += dp[i][j] / 8; // move up 2 and right 1
        if (i - 1 >= 0 && j - 2 >= 0) newDp[i - 1][j - 2] += dp[i][j] / 8; // move up 1 and left 2
        if (i - 1 >= 0 && j + 2 < m) newDp[i - 1][j + 2] += dp[i][j] / 8; // move up 1 and right 2
        if (i + 1 < n && j - 2 >= 0) newDp[i + 1][j - 2] += dp[i][j] / 8; // move down 1 and left 2
        if (i + 1 < n && j + 2 < m) newDp[i + 1][j + 2] += dp[i][j] / 8; // move down 1 and right 2
        if (i + 2 < n && j - 1 >= 0) newDp[i + 2][j - 1] += dp[i][j] / 8; // move down 2 and left 1
        if (i + 2 < n && j + 1 < m) newDp[i + 2][j + 1] += dp[i][j] / 8; // move down 2 and right 1
      }
    }
    dp = newDp; // Update the current dp array to the next step's probability
  }

  // Calculate and return final probability
  let probability = 0;
  for (let i = 0; i < n; i++) {
    for (let j = 0; j < m; j++) {
      probability += dp[i][j];
    }
  }
  return probability;
}

// JavaScript solution 2

function solution(n, m, steps, x, y) {
  let dp = Array.from({ length: n }, (v) => Array.from({ length: m }, (o) => []));
  function move(x, y, remain) {
    if (x < 0 || x >= n || y < 0 || y >= m) return 0;
    if (dp[x][y][remain] !== undefined) return dp[x][y][remain];
    if (!remain) return 1;
    let total = 0;
    for (let i = -2; i <= 2; i++) {
      for (let j = -2; j <= 2; j++) {
        if (Math.abs(i * j) === 2) {
          total += move(x + i, y + j, remain - 1) / 8;
        }
      }
    }
    return (dp[x][y][remain] = total);
  }
  return move(x, y, steps);
}

// Python solution

// def solution(n, m, steps, a, b):
//     dp=numpy.zeros((n,m))
//     dp[a,b]=1
//     for step in range(steps):
//         _dp=numpy.zeros((n,m))
//         for i in range(n):
//             for j in range(m):
//                 for x,y in (2,-1),(-1,2),(1,2),(2,1),(-1,-2),(-2,1),(1,-2),(-2,-1):
//                     if 0<=i+x<n and 0<=j+y<m:
//                         _dp[i+x,j+y]+=dp[i,j]/8
//         dp=_dp
//     return dp.sum()
