// write a function that takes in a grid containing Ws and Ls. W represents water and L represents
// land. the function should return the number of islands on the grid. An island is a vertically
// or horizontally connected region of land.

const grid = [
  ["W", "L", "W", "W", "W"],
  ["W", "L", "W", "W", "W"],
  ["W", "W", "W", "L", "W"],
  ["W", "W", "L", "L", "W"],
  ["L", "W", "W", "L", "L"],
  ["L", "L", "W", "W", "W"],
];

const islandCount = (grid) => {
  let count = 0;
  for (let i = 0; i < grid.length; i++) {
    for (let j = 0; j < grid[i].length; j++) {
      if (grid[i][j] === "L") {
        count++;
        markIsland(grid, i, j);
      }
    }
  }
  return count;
};

// traverse with a depth first search
const markIsland = (grid, i, j) => {
  if (i < 0 || j < 0 || i >= grid.length || j >= grid[i].length) {
    return;
  }
  if (grid[i][j] !== "L") {
    return;
  }
  grid[i][j] = "M";
  markIsland(grid, i + 1, j);
  markIsland(grid, i - 1, j);
  markIsland(grid, i, j + 1);
  markIsland(grid, i, j - 1);
};

console.log(islandCount(grid));
