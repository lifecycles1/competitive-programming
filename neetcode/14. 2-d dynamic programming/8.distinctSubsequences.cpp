// Given two strings s and t, return the number of distinct subsequences of s which equals t.

// The test cases are generated so that the answer fits on a 32-bit signed integer.

// top-down DFS + memo, cache on i & j indices to the # of distinct subseq
// 2 choices: if chars equal, look at remainder of both s & t
// if chars not equal, only look at remainder of s

// Time: O(m x n) 11% runtime
// Space: O(m x n)

#include <string>
#include <vector>
#include <map>
using namespace std;

class Solution {
public:
  int numDistinct(string s, string t) {
    return dfs(s, t, 0, 0);
  }
private:
  // {(i, j) -> # of distinct subsequences of s[i:] & t[j:]}
  map<pair<int, int>, int> dp;

  int dfs(string& s, string& t, int i, int j) {
    if (j == t.size()) {
      return 1;
    }
    if (i == s.size()) {
      return 0;
    }
    if (dp.find({i, j}) != dp.end()) {
      return dp[{i, j}];
    }
    if (s[i] == t[j]) {
      dp[{i, j}] = dfs(s, t, i+1, j+1) + dfs(s, t, i+1, j);
    } else {
      dp[{i, j}] = dfs(s, t, i+1, j);
    }
    return dp[{i, j}];
  }
};

// bottom up DP 85+% runtime
class Solution {
public:
  int numDistinct(string s, string t) {
    int tLen = t.size();
    vector<double> prefixVec(tLen,0);
    for (auto c: s) {
      for (int i = tLen-1;i >= 0;--i) {
        if (t[i] == c) {
          prefixVec[i] = (i > 0 ? prefixVec[i-1] : 1) + prefixVec[i];
        }
      }
    }
    return prefixVec.back();
  }
};

// almost the same as above bottom up DP 85+% runtime 
class Solution {
public:
  int numDistinct(string s, string t) {
    int n = s.length(), m = t.length();
    vector<double>dp(m+1, 0);
    dp[0] = 1;
    for(int i = 1; i <= n; i++) {
      for(int j = m; j > 0; j--) {
        if(s[i-1] == t[j-1]) {
          dp[j] = dp[j-1] + dp[j];
        }
      }
    }
    return dp[m];    
  }
};