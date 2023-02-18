// Given a string s containing only three types of characters: '(', ')' and '*', return true if s is valid.

// The following rules define a valid string:

// Any left parenthesis '(' must have a corresponding right parenthesis ')'.
// Any right parenthesis ')' must have a corresponding left parenthesis '('.
// Left parenthesis '(' must go before the corresponding right parenthesis ')'.
// '*' could be treated as a single right parenthesis ')' or a single left parenthesis '(' or 
// an empty string "".

#include <string>
using namespace std;

class Solution {
public:
  bool checkValidString(string s) {
    int n = s.size();

    int balanced = 0;
    for (int i = 0; i < n; i++) {
      if (s[i] == '(' || s[i] == '*') {
        balanced++;
      } else {
        balanced--;
      }
      if (balanced < 0) {
        return false;
      }
    }
    if (balanced == 0) {
      return true;
    }
    balanced = 0;
    for (int i = n-1; i >= 0; i--) {
      if (s[i] == ')' || s[i] == '*') {
        balanced++;
      } else {
        balanced--;
      }
      if (balanced < 0) {
        return false;
      }
    }
    return true;
  }
};