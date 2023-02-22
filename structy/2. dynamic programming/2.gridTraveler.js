// Say that you are a traveler on a 2D grid. You begin in the top-left corner and your goal is to
// travel to the bottom-right corner. You may only move down or right.

// In how many ways can you travel to the goal on a grid with dimensions m * n?

// Write a function 'gridTraveler(m, n)' that calculates this.

// // iterative tabulation solution
function gridTraveler(m, n) {
  const table = Array(m + 1)
    .fill()
    .map(() => Array(n + 1).fill(0));
  table[1][1] = 1;
  for (let i = 0; i <= m; i++) {
    for (let j = 0; j <= n; j++) {
      const current = table[i][j];
      if (j + 1 <= n) table[i][j + 1] += current;
      if (i + 1 <= m) table[i + 1][j] += current;
    }
  }
  return table[m][n];
}

// // recursive solution
function gridTraveler(m, n) {
  if (m === 1 && n === 1) return 1;
  if (m === 0 || n === 0) return 0;
  return gridTraveler(m - 1, n) + gridTraveler(m, n - 1);
}

// // memoized solution - dynamic programming
function gridTraveler(m, n, memo = {}) {
  const key = m + "," + n;
  if (key in memo) return memo[key];
  if (m === 1 && n === 1) return 1;
  if (m === 0 || n === 0) return 0;
  memo[key] = gridTraveler(m - 1, n, memo) + gridTraveler(m, n - 1, memo);
  return memo[key];
}

console.log(gridTraveler(2, 3)); // 3
