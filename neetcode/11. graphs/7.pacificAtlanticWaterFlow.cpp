// There is an m x n rectangular island that borders both the Pacific Ocean and Atlantic Ocean. 
// The Pacific Ocean touches the island's left and top edges, and the Atlantic Ocean touches the 
// island's right and bottom edges.

// The island is partitioned into a grid of square cells. You are given an m x n integer matrix heights 
// where heights[r][c] represents the height above sea level of the cell at coordinate (r, c).

// The island receives a lot of rain, and the rain water can flow to neighboring cells directly north, 
// south, east, and west if the neighboring cell's height is less than or equal to the current cell's 
// height. Water can flow from any cell adjacent to an ocean into the ocean.

// Return a 2D list of grid coordinates result where result[i] = [ri, ci] denotes that rain water can 
// flow from cell (ri, ci) to both the Pacific and Atlantic oceans.

// Top & left pacific, bottom & right atlantic, determine spots that flow to both
// Instead go outside in, from oceans to spots where rain could flow from
// Faster bc avoids repeated work: cells along a path can also reach that ocean
// Time: O(m x n)
// Space: O(m x n)

#include <vector>
using namespace std;

class Solution {
public:
  vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
    int m = heights.size();
    int n = heights[0].size();

    vector<vector<bool>> pacific(m, vector<bool>(n));
    vector<vector<bool>> atlantic(m, vector<bool>(n));

    for (int i = 0; i < m; i++) {
      dfs(heights, pacific, i, 0, m, n);
      dfs(heights, atlantic, i, n-1, m, n);
    }
    for (int j = 0; j < n; j++) {
      dfs(heights, pacific, 0, j, m, n);
      dfs(heights, atlantic, m-1, j, m, n);
    }
    vector<vector<int>> result;
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        if (pacific[i][j] && atlantic[i][j]) {
          result.push_back({i, j});
        }
      }
    }
    return result;
  }
private:
  void dfs(vector<vector<int>>& heights, vector<vector<bool>>& visited, int i, int j, int m, int n) {
    visited[i][j] = true;
    if (i > 0 && !visited[i-1][j] && heights[i-1][j] >= heights[i][j]) {
      dfs(heights, visited, i-1, j, m, n);
    }
    if (i < m-1 && !visited[i+1][j] && heights[i+1][j] >= heights[i][j]) {
      dfs(heights, visited, i+1, j, m, n);
    }
    if (j > 0 && !visited[i][j-1] && heights[i][j-1] >= heights[i][j]) {
      dfs(heights, visited, i, j-1, m, n);
    }
    if (j < n-1 && !visited[i][j+1] && heights[i][j+1] >= heights[i][j]) {
      dfs(heights, visited, i, j+1, m, n);
    }
  }
};