// Given a string s, return the number of unique palindromes of length three that are a subsequence of s.

// Note that even if there are multiple ways to obtain the same subsequence, it is still only counted once.

// A palindrome is a string that reads the same forwards and backwards.

// A subsequence of a string is a new string generated from the original string with some characters 
// (can be none) deleted without changing the relative order of the remaining characters.

// For example, "ace" is a subsequence of "abcde"

# include <string>
# include <vector>
# include <unordered_set>
using namespace std;

class Solution {
public:
  int countPalindromicSubsequence(string s) {
    vector<pair<int, int>> v(26, {-1, -1});
    for (int i = 0; i < s.size(); i++) {
      if (v[s[i] - 'a'].first == -1) {
        v[s[i] - 'a'].first = i;
      } else {
        v[s[i] - 'a'].second = i;
      }
    }
    int res = 0;
    for (int i = 0; i < 26; i++) {
      if (v[i].second != -1) {
        unordered_set<char> tmp;
        for (int j = v[i].first + 1; j < v[i].second; j++) {
          tmp.insert(s[j]);
        }
        res += tmp.size();
      }
    }
    return res;
  }
};