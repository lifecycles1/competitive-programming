// A group of farmers has some elevation data that we are going to use to help them understand how
// rainfall flows over their farmland. We represent the farmland as a 2D array of altitudes,
// the grid, and use the following model, based on the fact that water flows downhill:

// If a cell's four neighboring cells all have altitudes not lower that its own, this cell is a
// sink in which water collects.
// Otherwise, water will flow into the neighboring cell with the lowest altitude. If a cell is
// not a sink, you can assume it has a unique lowest neighbor and that this neighbor will be lower
// than the cell.
// Cells that drain into the same sink, directly or indirectly, are part of the same basin.
// Given an n × n grid of elevations, your goal is to partition the map into basins and output
// the sizes of the basins, in descending order.

class Solution {
  /* Algorithm:
   * Loop through cells ordered by value:
   *  Grab lowest neighbor's basin and make our own.
   *  If no neighbors are lower, cell is a basin.
   *  Enter and/or increment this basin in basin_count.
   */
  solution(grid) {
    var sides = [
      [-1, 0],
      [1, 0],
      [0, -1],
      [0, 1],
    ];
    var queue = [];
    var results = {};

    const nGrid = grid.map((row, r) =>
      row.map((v, c) => {
        var t = { val: v, loc: [r, c] };
        queue.push(t);
        return t;
      })
    );

    // Assuming JS sort is O(NlogN). If not, use insert sort above.
    queue
      .sort((a, b) => a.val - b.val)
      .forEach((cell) => {
        var [R, C] = cell.loc;
        var lowest = sides.reduce((p, [r, c]) => {
          var t = (nGrid[R + r] || 0)[C + c];
          return t && t.val < p.val ? t : p;
        }, cell);

        cell.basin = lowest.basin || lowest.loc;
        results[cell.basin] = -~results[cell.basin];
      });

    return Object.keys(results)
      .map((k) => results[k])
      .sort((a, b) => b - a);
  }
}
