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

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
  vector<int> calculateBasins(vector<vector<int>> grid) {
    int x = grid.size();
    int y = grid[0].size();
    vector<vector<int>> sink(x, vector<int>(y, -1));
    vector<int> ans;
    for (int i = 0; i < x; i++) {
      for (int j = 0; j < y; j++) {
        ++ans[find(grid, sink, i, j, x, y, ans)];
      }
    }
    sort(ans.begin(), ans.end(), greater<int>());
    return ans;
  }
private:
  int find(vector<vector<int>>& grid, vector<vector<int>>& sink, int i, int j, int x, int y, vector<int>& ans) {
    if (sink[i][j] != -1) {
      return sink[i][j];
    }
    int minI = i, minJ = j, minV = grid[i][j];
    if (i && grid[i-1][j] < minV) {
      minI = i-1, minJ = j, minV = grid[i-1][j];
    }
    if (j && grid[i][j-1] < minV) {
      minI = i, minJ = j-1, minV = grid[i][j-1];
    }
    if (i < x-1 && grid[i+1][j] < minV) {
      minI = i+1, minJ = j, minV = grid[i+1][j];
    }
    if (j < y-1 && grid[i][j+1] < minV) {
      minI = i, minJ = j+1, minV = grid[i][j+1];
    }
    if (minI == i && minJ == j) {
      ans.push_back(0);
      sink[i][j] = ans.size() - 1;
    } else {
      sink[i][j] = find(grid, sink, minI, minJ, x, y, ans);
    }
    return sink[i][j];
  }
};