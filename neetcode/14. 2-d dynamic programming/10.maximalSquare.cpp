// Given an m x n binary matrix filled with 0's and 1's, 
// find the largest square containing only 1's and return its area.

#include <vector>
using namespace std;

// not the python version, 95% faster runtime
class Solution {
public:
  int maximalSquare(vector<vector<char>>& matrix) {
    int m = matrix.size();
    if(m==0) return 0;
    int n = matrix[0].size();
  
    vector<vector<int>> dp(m+1, vector<int>(n+1, 0));
  
    int ret = 0;
    for(int i = 1; i <= m; i ++) {
      for(int j = 1; j <= n; j ++) {
        if(matrix[i-1][j-1] == '0') {
          dp[i][j] = 0;
        } else {
          dp[i][j] = 1 + min(dp[i-1][j], min(dp[i][j-1], dp[i-1][j-1]));
        }
        ret = max(ret, dp[i][j]);
      }
    }

    return ret*ret;
  }
};