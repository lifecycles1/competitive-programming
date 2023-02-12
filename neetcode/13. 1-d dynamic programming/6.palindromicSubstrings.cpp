// Given a string s, return the number of palindromic substrings in it.

// A string is a palindrome when it reads the same backward as forward.

// A substring is a contiguous sequence of characters within the string.

#include <string>
using namespace std;

class Solution {
public:
  int countSubstrings(string s) {
    int result = 0;

    for (int i = 0; i < s.size(); i++) {
      middleOut(s, i, i, result);
      middleOut(s, i, i+1, result);
    }

    return result;
  }
private:
  void middleOut(string s, int i, int j, int& result) {
    while (i >=0 && j < s.size() && s[i] == s[j]) {
      result++;
      i--;
      j++;
    }
  }
};