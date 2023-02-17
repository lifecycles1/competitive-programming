// Given an integer n, break it into the sum of k positive integers, where k >= 2, 
// and maximize the product of those integers.

// Return the maximum product you can get.

#include <unordered_map>
#include <functional>
#include <algorithm>
using namespace std;

// recursive solution
class Solution {
public:
  int integerBreak(int n) {
    unordered_map<int, int> dp;
    dp[1] = 1;

    function<int(int)> dfs = [&](int num) -> int {
      if (dp.find(num) != dp.end()) {
        return dp[num];
      }
      // dp[num] = 0 ? num == n : num;
      if (num == n) {
        dp[num] = 0;
      } else {
        dp[num] = num;
      }
      for (int i = 1; i < num; i++) {
        int val = dfs(i) * dfs(num - i);
        dp[num] = max(dp[num], val);
      }
      return dp[num];
    };

    return dfs(n);
  }
};

// actual dp solution
class Solution {
public:
  int integerBreak(int n) {
    unordered_map<int, int> dp;
    dp[1] = 1;

    for (int num = 2; num < n+1; num++) {
      if (num == n) {
        dp[num] = 0;
      } else {
        dp[num] = num;
      }
      for (int i = 1; i < num; i++) {
        int val = dp[i] * dp[num - i];
        dp[num] = max(dp[num], val);
      }
    }

    return dp[n];
  }
};