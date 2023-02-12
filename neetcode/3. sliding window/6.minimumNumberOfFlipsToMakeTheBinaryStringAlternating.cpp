// You are given a binary string s. You are allowed to perform two types of operations on the 
// string in any sequence:

// Type-1: Remove the character at the start of the string s and append it to the end of the string.
// Type-2: Pick any character in s and flip its value, i.e., if its value is '0' it becomes '1' 
// and vice-versa.
// Return the minimum number of type-2 operations you need to perform such that s becomes alternating.

// The string is called alternating if no two adjacent characters are equal.

// For example, the strings "010" and "1010" are alternating, while the string "0100" is not.

#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
  int minFlips(string s) {
    int n = s.size();
    s += s;
    string alt1 = "", alt2 = "";
    for (int i = 0; i < s.size(); i++) {
      alt1 += (i % 2) ? '0' : '1';
      alt2 += (i % 2) ? '1' : '0';
    }
    
    int res = s.size();
    int diff1 = 0, diff2 = 0;
    int l = 0;
    for (int r = 0; r < s.size(); r++) {
      if (s[r] != alt1[r]) diff1++;
      if (s[r] != alt2[r]) diff2++;
      
      if (r - l + 1 > n) {
        if (s[l] != alt1[l]) diff1--;
        if (s[l] != alt2[l]) diff2--;
        l++;
      }
      
      if (r - l + 1 == n) {
        res = min(res, min(diff1, diff2));
      }
    }
    return res;
  }
};