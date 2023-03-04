// Given a string, check if it can become a palindrome through a case change of some 
// (possibly, none) letters

#include <string>

class Solution {
public:
  bool isCaseInsensitivePalindrome(std::string inputString) {
    int len = inputString.length();
    for (int i = 0; i < len / 2; i++) {
      if (tolower(inputString[i]) != tolower(inputString[len - i - 1])) return false;
    }
    return true;
  }
};