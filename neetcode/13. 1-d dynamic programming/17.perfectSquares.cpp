#include <vector>
#include <algorithm>

class Solution {
public:
  int numSquares(int n) {
    // vector for updating the dp array/values
    std::vector<int> dp(n+1, INT_MAX);
    // base case
    dp[0] = 0;
    int count = 1;
    while (count*count <= n) {
      int sq = count*count;
      for (int i = sq; i < n+1; i++) {
        dp[i] = std::min(dp[i-sq] + 1, dp[i]);
      }
      count++;
    }
    return dp[n];
  }
};