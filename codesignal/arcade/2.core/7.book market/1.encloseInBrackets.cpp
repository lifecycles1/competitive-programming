// Given a string, enclose it in round brackets.

#include <string>

class Solution {
public:
  std::string encloseInBrackets(std::string inputString) {
    return "(" + inputString + ")";
  }
};