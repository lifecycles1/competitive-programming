// Given a string s and a dictionary of strings wordDict, add spaces in s to construct a sentence 
// where each word is a valid dictionary word. Return all such possible sentences in any order.

// Note that the same word in the dictionary may be reused multiple times in the segmentation.

// Input: s = "catsanddog", wordDict = ["cat","cats","and","sand","dog"]
// Output: ["cats and dog","cat sand dog"]

# include <string>
# include <vector>
# include <unordered_set>
using namespace std;

class Solution {
public:
  vector<string> wordBreak(string s, vector<string>& wordDict) {
    unordered_set<string> dict(wordDict.begin(), wordDict.end());
    vector<bool> dp(s.size() + 1, false);
    dp[0] = true;
    for (int i = 1; i <= s.size(); i++) {
      for (int j = i - 1; j >= 0; j--) {
        if (dp[j] && dict.count(s.substr(j, i - j))) {
          dp[i] = true;
          break;
        }
      }
    }
    vector<string> res;
    if (!dp[s.size()]) return res;
    vector<string> path;
    dfs(s, dict, 0, path, res, dp);
    return res;
  }
  void dfs(string& s, unordered_set<string>& dict, int start, vector<string>& path, vector<string>& res, vector<bool>& dp) {
    if (start == s.size()) {
      string str = path[0];
      for (int i = 1; i < path.size(); i++) {
        str += " " + path[i];
      }
      res.push_back(str);
      return;
    }
    for (int i = start + 1; i <= s.size(); i++) {
      string str = s.substr(start, i - start);
      if (dict.count(str) && dp[i]) {
        path.push_back(str);
        dfs(s, dict, i, path, res, dp);
        path.pop_back();
      }
    }
  }
};
