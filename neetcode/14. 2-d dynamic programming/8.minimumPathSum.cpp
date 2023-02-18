// Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right, 
// which minimizes the sum of all numbers along its path.

// Note: You can only move either down or right at any point in time.

#include <vector>
using namespace std;

class Solution {
public:
  int minPathSum(vector<vector<int>>& grid) {
    int m = grid.size();
    int n = grid[0].size();
    vector<int> prev(n, INT_MAX);
    prev[n-1] = 0;

    for (int row = m-1; row >= 0; row--) {
      vector<int> dp(n, INT_MAX);
      for (int col = n-1; col >= 0; col--) {
        if (col < n-1) {
          dp[col] = min(dp[col], dp[col+1]);
        }
        dp[col] = min(dp[col], prev[col]) + grid[row][col];
      }
      prev = dp;
    }

    return prev[0];
  }
};