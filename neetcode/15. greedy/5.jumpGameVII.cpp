// You are given a 0-indexed binary string s and two integers minJump and maxJump. 
// In the beginning, you are standing at index 0, which is equal to '0'. 
// You can move from index i to index j if the following conditions are fulfilled:

// i + minJump <= j <= min(i + maxJump, s.length - 1), and
// s[j] == '0'.
// Return true if you can reach index s.length - 1 in s, or false otherwise.

# include <string>
# include <vector>
using namespace std;

class Solution {
public:
  bool canReach(string s, int minJ, int maxJ) {
    int n = s.size(), pre = 0;
    vector<bool> dp(n, false);
    dp[0] = true;
    for (int i = 1; i < n; ++i) {
      if (i >= minJ)
        pre += dp[i - minJ];
      if (i > maxJ)
        pre -= dp[i - maxJ - 1];
      dp[i] = pre > 0 && s[i] == '0';
    }
    return dp[n - 1];
  }
};