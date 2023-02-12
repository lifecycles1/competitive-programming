// Given strings s1, s2, and s3, find whether s3 is formed by an interleaving of s1 and s2.

// An interleaving of two strings s and t is a configuration where s and t are divided into n and m 
// substrings respectively, such that:

// s = s1 + s2 + ... + sn
// t = t1 + t2 + ... + tm
// |n - m| <= 1
// The interleaving is s1 + t1 + s2 + t2 + s3 + t3 + ... or t1 + s1 + t2 + s2 + t3 + s3 + ...
// Note: a + b is the concatenation of strings a and b.

// DFS + memo, cache on s1 & s2 indices i & j
// 2 choices: either take s1 & iterate i, or take s2 & iterate j

//  Time: O(m x n)
//  Space: O(m x n)
# include <string>
# include <map>
# include <vector>
using namespace std;

class Solution {
public:
  bool isInterleave(string s1, string s2, string s3) {
    if (s3.size() != s1.size() + s2.size()) {
      return false;
    }
    return dfs(s1, s2, s3, 0, 0);
  }
private:
  map<pair<int, int>, bool> dp;

  bool dfs(string s1, string s2, string s3, int i, int j) {
    if (i == s1.size() && j == s2.size()) {
      return true;
    }
    if (dp.find({i, j}) != dp.end()) {
      return dp[{i, j}];
    }
    if (i < s1.size() && s1[i] == s3[i+j] && dfs(s1, s2, s3, i+1, j)) {
      return true;
    }
    if (j < s2.size() && s2[j] == s3[i+j] && dfs(s1, s2, s3, i, j+1)) {
      return true;
    }
    dp[{i, j}] = false;
    return dp[{i, j}];
  }
};

// optimized time
class Solution1 {
public:
  bool isInterleave(string s1, string s2, string s3) {
    if (s1.length() + s2.length() != s3.length()) {
      return false;
    }

    vector<vector<bool>> dp(s1.length()+1, vector<bool>(s2.length()+1, false));
    dp[0][0]=true;

    for (int i = 1; i <= s1.length(); i++) {
      dp[i][0] = dp[i-1][0] && s1[i-1] == s3[i-1];
    }
    for (int i = 1; i <= s2.length(); i++) {
      dp[0][i] = dp[0][i-1] && s2[i-1] == s3[i-1];
    }
    for (int i = 1; i <= s1.length(); i++) {
      for (int j = 1; j <= s2.length(); j++) {
        dp[i][j] = (dp[i-1][j] && s1[i-1] == s3[i+j-1]) || (dp[i][j-1] && s2[j-1] == s3[i+j-1]);
      }
    }
    return dp[s1.length()][s2.length()];
  }
};