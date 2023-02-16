// You are given two m x n binary matrices grid1 and grid2 containing only 0's 
// (representing water) and 1's (representing land). An island is a group of 1's connected 
// 4-directionally (horizontal or vertical). Any cells outside of the grid are considered 
// water cells.

// An island in grid2 is considered a sub-island if there is an island in grid1 that contains 
// all the cells that make up this island in grid2.

// Return the number of islands in grid2 that are considered sub-islands.

#include <vector>
using namespace std;

class Solution {
public:
  int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
    int m = grid1.size();
    int n = grid1[0].size();
    int result = 0;

    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        if (grid2[i][j] == 1) {
          result += dfs(grid1, grid2, i, j, m, n);
        }
      }
    }
    return result;
  }
private:
  int dfs(vector<vector<int>>& grid1, vector<vector<int>>& grid2, int i, int j, int m, int n) {
    if (i < 0 || i >= m || j < 0 || j >= n || grid2[i][j] == 0) {
      return 1;
    }
    grid2[i][j] = 0;

    int result = dfs(grid1, grid2, i-1, j, m, n) & dfs(grid1, grid2, i+1, j, m, n) &
                 dfs(grid1, grid2, i, j-1, m, n) & dfs(grid1, grid2, i, j+1, m, n);
    
    return result & grid1[i][j];
  }
};