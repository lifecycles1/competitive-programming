// Check whether the given string is a subsequence of the plaintext alphabet.

#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
  bool alphabetSubsequence(string s) {
    return is_sorted(s.begin(), s.end()) && adjacent_find(s.begin(), s.end()) == s.end();
  }
};

class Solution {
public:
  bool alphabetSubsequence(string s) {
    for (int m = 1; m < s.length(); m++) {
      if (s[m] <= s[m-1]) {
        return false;
      }
    }
    return true;
  }
};