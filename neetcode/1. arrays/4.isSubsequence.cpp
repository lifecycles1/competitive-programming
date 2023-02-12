// Given two strings s and t, return true if s is a subsequence of t, or false otherwise.

// A subsequence of a string is a new string that is formed from the original string by deleting some 
// (can be none) of the characters without disturbing the relative positions of the remaining characters. 
// (i.e., "ace" is a subsequence of "abcde" while "aec" is not).

// Time Complexity is O(N) where n is the size of the target string.
// Space Complexity is O(1)

#include <string>
using namespace std;

class Solution {
public:
  bool isSubsequence(string s, string t) {
    int i = 0, j = 0;
    while (j < s.size() && i < t.size()) {
      if (s[j] == t[i]) {
        j++;
      }
      i++;
    }
    if (j >= s.size()) {
      return true;
    }
    return false;
  }
};