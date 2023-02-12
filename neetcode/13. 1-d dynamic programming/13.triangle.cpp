// Given a triangle array, return the minimum path sum from top to bottom.

// For each step, you may move to an adjacent number of the row below. More formally, if you are 
// on index i on the current row, you may move to either index i or index i + 1 on the next row.

#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
  int minimumTotal(vector<vector<int>> triangle) {
    int l = triangle.size();
    vector<int> dp(l+1, 0);

    for (int row = l-1; row > -1; row--) {
      for (int col = 0; col < row+1; col++) {
        dp[col] = triangle[row][col] + min(dp[col], dp[col+1]);
      }
    }
    return dp[0];
  }
};