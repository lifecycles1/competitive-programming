// You are given a 0-indexed 2D array grid of size 2 x n, where grid[r][c] represents the number of 
// points at position (r, c) on the matrix. Two robots are playing a game on this matrix.

// Both robots initially start at (0, 0) and want to reach (1, n-1). Each robot may only move to the 
// right ((r, c) to (r, c + 1)) or down ((r, c) to (r + 1, c)).

// At the start of the game, the first robot moves from (0, 0) to (1, n-1), collecting all the points 
// from the cells on its path. For all cells (r, c) traversed on the path, grid[r][c] is set to 0. 
// Then, the second robot moves from (0, 0) to (1, n-1), collecting the points on its path. 
// Note that their paths may intersect with one another.

// The first robot wants to minimize the number of points collected by the second robot. 
// In contrast, the second robot wants to maximize the number of points it collects. 
// If both robots play optimally, return the number of points collected by the second robot.

// Approch:
// 2nd robot can collect either all the bottom points
// before the break point (when 1st robot goes to bottom)
// or collect all the top points after that break point.
// Time Complexity: O(N)
// Space Complexity: O(1)

# include <vector>
using namespace std;

class Solution {
public:
  long long gridGame(vector<vector<int>>& grid) {
    // prefix sum
    long long top = grid[0][0];
    long long bottom = 0;
    long long answer = LONG_MAX;
    for (int i = 1; i < grid[0].size(); i++) {
      top += grid[0][i];
    }
    for (int i = 0; i < grid[0].size(); i++) {
      // all the top points 2nd robot can collect
      top -= grid[0][i];

      // min because first robot wants to minimize
      answer = min(answer, max(top, bottom));

      // all the bottom points the robot could collect
      bottom += grid[1][i];
    }
    return answer;
  }
};