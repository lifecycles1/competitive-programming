// You are given an m x n binary matrix grid. An island is a group of 1's (representing land) connected 
// 4-directionally (horizontal or vertical.) You may assume all four edges of the grid are surrounded 
// by water.

// The area of an island is the number of cells with a value 1 in the island.

// Return the maximum area of an island in grid. If there is no island, return 0.

// Given grid where '1' is land & '0' is water, return largest island
// DFS, set visited land to '0' to not visit it again, store biggest
// Time: O(m x n)
// Space: O(m x n)

#include <vector>
using namespace std;

class Solution {
public:
  int maxAreaOfIsland(vector<vector<int>>& grid) {
    int m = grid.size();
    int n = grid[0].size();
    int result = 0;

    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        if (grid[i][j] == 1) {
          result = max(result, dfs(grid, i, j, m, n));
        }
      }
    }
    return result;
  }
private:
  int dfs(vector<vector<int>>& grid, int i, int j, int m, int n) {
    if (i < 0 || i >= m || j < 0 || j >= n || grid[i][j] == 0) {
      return 0;
    }
    grid[i][j] = 0;

    return 1  + dfs(grid, i-1, j, m, n) + dfs(grid, i+1, j, m, n) +
                dfs(grid, i, j-1, m, n) + dfs(grid, i, j+1, m, n);
  }
};
