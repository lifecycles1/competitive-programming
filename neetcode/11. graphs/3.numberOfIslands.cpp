// Given an m x n 2D binary grid grid which represents a map of '1's (land) and '0's (water), 
// return the number of islands.

// An island is surrounded by water and is formed by connecting adjacent lands horizontally or 
// vertically. You may assume all four edges of the grid are all surrounded by water.

// DFS, set visited land to '0' to not visit it again, count islands
// Time: O(m x n)
// Space: O(m x n)

# include <vector>
using namespace std;

class Solution {
public:
  int numIslands(vector<vector<char>>& grid) {
    int m = grid.size();
    int n = grid[0].size();

    int result = 0;

    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        if (grid[i][j] == '1') {
          dfs(grid, i, j, m, n);
          result++;
        }
      }
    }
    return result;
  }

private:
  void dfs(vector<vector<char>>& grid, int i, int j, int m, int n) {
    if (i < 0 || i >= m || j < 0 || j >= n || grid[i][j] == '0') {
      return;
    }
    grid[i][j] = '0';

    dfs(grid, i-1, j, m, n);
    dfs(grid, i+1, j, m, n);
    dfs(grid, i, j-1, m, n);
    dfs(grid, i, j+1, m, n);
  }
};