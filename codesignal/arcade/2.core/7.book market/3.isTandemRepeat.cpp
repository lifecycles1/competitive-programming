// Determine whether the given string can be obtained by one concatenation of some string to itself.

#include <string>

class Solution {
public:
  bool isTandemRepeat(std::string inputString) {
    int len = inputString.length();
    if (len % 2 != 0) return false;
    return inputString.substr(0, len / 2) == inputString.substr(len / 2, len / 2);
  }
};