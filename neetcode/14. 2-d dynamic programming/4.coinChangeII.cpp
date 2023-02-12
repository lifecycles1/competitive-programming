// Companies
// You are given an integer array coins representing coins of different denominations and an integer 
// amount representing a total amount of money.

// Return the number of combinations that make up that amount. If that amount of money cannot be made 
// up by any combination of the coins, return 0.

// You may assume that you have an infinite number of each kind of coin.

// The answer is guaranteed to fit into a signed 32-bit integer.

// bottom-up dp approach
// O(amount * n) in time and O(amount) in space

#include <vector>
using namespace std;

class Solution {
public:
  int change(int amount, vector<int>& coins) {
      vector<int> dp(amount+1, 0);
      dp[0] = 1;

      for (int coin: coins) {
          for (int i = coin; i < amount+1; i++) {
              dp[i] += dp[i-coin];
          }
      }
      return (dp[amount] > 0 ? dp[amount] : 0);
  }
};