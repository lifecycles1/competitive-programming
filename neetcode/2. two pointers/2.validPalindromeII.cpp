// Given a string s, return true if the s can be palindrome after deleting at most one character from it.

#include <string>
using namespace std;

// 65% runtime
class Solution {
private:
  bool validPalindromeUtil(string s, int i, int j) {
    while (i < j) {
      if (s[i] == s[j]) {
        i += 1;
        j -= 1;
      } else {
        return false;
      }
    }
    return true;
  }
public:
  bool validPalindrome(string s) {
    int i = 0;
    int j = s.length() -1;
    while (i < j) {
      if (s[i] == s[j]) {
        i += 1;
        j -= 1;
      } else {
        return validPalindromeUtil(s, i+1, j) || validPalindromeUtil(s, i, j-1);
      }
    }
    return true;
  }
};

// 90% runtime
class Solution {
public:
  bool validPalindrome(string s) {
    int lo = 0;
    int hi = s.size() - 1;
    return validPalindromeUtil(s, lo, hi, 0);
  }

  bool validPalindromeUtil(string& s, int lo, int hi, int count) {
    if (count > 1) {
      return false;
    }
    while (lo < hi) {
      if (s[lo] == s[hi]) {
        lo++;
        hi--;
      } else {
        return validPalindromeUtil(s, lo+1, hi, count+1) || validPalindromeUtil(s, lo, hi-1, count+1);
      }
    }
    return true;
  }
};

// 90% runtime a bit easier to read than above
class Solution {
public:
  bool validPalindrome(string s) {
    for (int i = 0, j = s.size() - 1; i < j; i++, j--) {
      if (s[i] != s[j]) {
        return isp(s, i + 1, j) || isp(s, i, j - 1);
      }
    }
    return true;
  }

private:
  bool isp(string s, int l, int r) {
    for (int i = l, j = r; i < j; i++, j--) {
      if (s[i] != s[j]) {
        return false;
      }
    }
    return true;
  }
};