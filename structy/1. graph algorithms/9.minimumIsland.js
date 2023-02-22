// write a function that takes in a grid containing Ws and Ls. W represents water and L represents
// land. the function should return the size of the smallest island. an island is a vertically or
// horizontally connected region of land.

const grid = [
  ["W", "L", "W", "W", "W"],
  ["W", "L", "W", "W", "W"],
  ["W", "W", "W", "L", "W"],
  ["W", "W", "L", "L", "W"],
  ["L", "W", "W", "L", "L"],
  ["L", "L", "W", "W", "W"],
]; // -> 2

const minimumIsland = (grid) => {
  let minSize = Infinity;
  for (let r = 0; r < grid.length; r++) {
    for (let c = 0; c < grid[r].length; c++) {
      if (grid[r][c] === "L") {
        const size = exploreSize(grid, r, c);
        if (size > 0 && size < minSize) {
          minSize = size;
        }
      }
    }
  }
  return minSize;
};

const exploreSize = (grid, r, c) => {
  if (r < 0 || c < 0 || r >= grid.length || c >= grid[r].length) {
    return 0;
  }
  if (grid[r][c] !== "L") {
    return 0;
  }
  grid[r][c] = "M";
  return 1 + exploreSize(grid, r + 1, c) + exploreSize(grid, r - 1, c) + exploreSize(grid, r, c + 1) + exploreSize(grid, r, c - 1);
};

console.log(minimumIsland(grid));
