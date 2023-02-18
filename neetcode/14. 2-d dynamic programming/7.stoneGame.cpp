// Alice and Bob play a game with piles of stones. There are an even number of piles arranged 
// in a row, and each pile has a positive integer number of stones piles[i].

// The objective of the game is to end with the most stones. The total number of stones across 
// all the piles is odd, so there are no ties.

// Alice and Bob take turns, with Alice starting first. Each turn, a player takes the entire pile 
// of stones either from the beginning or from the end of the row. This continues until there are 
// no more piles left, at which point the person with the most stones wins.

// Assuming Alice and Bob play optimally, return true if Alice wins the game, or false if Bob wins.

#include <vector>
#include <unordered_map>
#include <string>
#include <functional>
#include <numeric>
using namespace std;

// slow solution, 5% faster runtime
class Solution {
public:
  bool stoneGame(vector<int>& piles) {
    int n = piles.size();
    unordered_map<string, int> dp;

    function<int(int, int)> dfs = [&](int l, int r) -> int {
      if (l > r) {
        return 0;
      }
      string key = to_string(l) + ',' + to_string(r);
      if (dp.count(key)) {
        return dp[key];
      }
      bool even = (r - l) % 2 == 0;
      int left = even ? piles[l] : 0;
      int right = even ? piles[r] : 0;
      int takeLeft = dfs(l+1, r) + left;
      int takeRight = dfs(l, r-1) + right;
      dp[key] = max(takeLeft, takeRight);
      return dp[key];
    };

    return dfs(0, n-1) > accumulate(piles.begin(), piles.end(), 0) / 2;
  }
};

// a bit faster, 30% runtime
class Solution {
public:
  bool stoneGame(vector<int>& piles) {
      int n = piles.size();
      vector<vector<int>>dp(n, vector<int>(n));
      
      for(int gap = 0; gap < n; gap++)
        for(int i = 0, j = gap; j < n; i++, j++) {
          if(gap == 0) dp[i][j] = piles[i];
          else if(gap == 1) dp[i][j] = max(piles[i], piles[j]);
          else {
            int case1 = piles[i] + min(dp[i+2][j], dp[i+1][j-1]);
            int case2 = piles[j] + min(dp[i+1][j-1], dp[i][j-2]);
            dp[i][j] = max(case1, case2); // maximum of these 2 cases
          }
        }
      return dp[0][n-1];
  }
};

// 95% runtime
class Solution {
public:
  bool stoneGame(vector<int>& piles) {
    return true;
  }
};

// 30% faster runtime
class Solution {
public:
  bool stoneGame(vector<int>& piles) {
    int n = piles.size();
    vector<vector<int>> dp(n, vector<int>(n, 0));

    for (int i = 0; i < n; i++) {
      dp[i][i] = piles[i];
    }

    for (int d = 1; d < n; d++) {
      for (int i = 0; i < n-d; i++) {
        int j = i+d;
        dp[i][j] = max(piles[i] - dp[i+1][j], piles[j] - dp[i][j-1]);
      }
    }

    return dp[0][n-1] > 0;
  }
};