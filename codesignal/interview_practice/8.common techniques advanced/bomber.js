// Each cell in a 2D grid contains either a wall ('W') or an enemy ('E'), or is empty ('0'). Bombs can destroy
// enemies, but walls are too strong to be destroyed. A bomb placed in an empty cell destroys all enemies in the
// same row and column, but the destruction stops once it hits a wall.

// Return the maximum number of enemies you can destroy using one bomb.

// Note that your solution should have O(field.length · field[0].length) complexity

// Example

// For

// field = [["0", "0", "E", "0"],
//          ["W", "0", "W", "E"],
//          ["0", "E", "0", "W"],
//          ["0", "W", "0", "E"]]
// the output should be
// solution(field) = 2.

// Placing a bomb at (0, 1) or at (0, 3) destroys 2 enemies.

const solution = (field) => {
  if (!field.length) return 0;
  let m = 0;
  let height = field.length;
  let width = field[0].length;
  for (i = 0; i < height; i++) {
    for (j = 0; j < width; j++) {
      if (!"WE".includes(field[i][j])) {
        let n = 0;
        for (k = 1; i - k >= 0; k++) {
          if (field[i - k][j] == "W") break;
          if (field[i - k][j] == "E") n++;
        }
        for (k = 1; i + k < height; k++) {
          if (field[i + k][j] == "W") break;
          if (field[i + k][j] == "E") n++;
        }
        for (k = 1; j - k >= 0; k++) {
          if (field[i][j - k] == "W") break;
          if (field[i][j - k] == "E") n++;
        }
        for (k = 1; j + k < width; k++) {
          if (field[i][j + k] == "W") break;
          if (field[i][j + k] == "E") n++;
        }
        m = Math.max(m, n);
      }
    }
  }
  return m;
};

// solution = (field) => {
//   let walls = [];
//   let enemies = [];
//   for (i in field) {
//     for (j in field[i]) {
//       if (field[i][j] === "W") walls.push([i, j]);
//       if (field[i][j] === "E") enemies.push([i, j]);
//     }
//   }
//   // console.log(walls, enemies);
//   let maxCasualties = 0;

//   calculateCasualties = (x, y) => {
//     if ("WE".includes(field[x][y])) return 0;
//     w = walls.filter((wall) => wall[0] === x || wall[1] === y);
//     e = enemies.filter((enemy) => enemy[0] === x || enemy[1] === y);
//     // console.log(e)
//     return e.reduce((t, enemy, i) => {
//       a = enemy[0] === x && !w.some((wall) => wall[0] === x && ((wall[1] > enemy[1] && wall[1] < y) || (wall[1] < enemy[1] && wall[1] > y)));
//       b = enemy[1] === y && !w.some((wall) => wall[1] === y && ((wall[0] > enemy[0] && wall[0] < x) || (wall[0] < enemy[0] && wall[0] > x)));
//       return t + (a || b ? 1 : 0);
//     }, 0);
//   };

//   for (i in field) {
//     for (j in field[i]) {
//       maxCasualties = Math.max(maxCasualties, calculateCasualties(i, j));
//     }
//   }

//   return maxCasualties;
// };
