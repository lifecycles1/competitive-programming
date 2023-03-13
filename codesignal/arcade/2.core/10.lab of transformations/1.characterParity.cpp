// Given a character, check if it represents an odd digit, an even digit or not a digit at all.

// Example

// For symbol = '5', the output should be
// solution(symbol) = "odd";
// For symbol = '8', the output should be
// solution(symbol) = "even";
// For symbol = 'q', the output should be
// solution(symbol) = "not a digit".

#include <string>

class Solution {
public:
  std::string solution(char symbol) {
    if (symbol >= '0' && symbol <= '9') {
      if ((symbol - '0') % 2 == 0) {
        return "even";
      } else {
        return "odd";
      }
    } else {
      return "not a digit";
    }
  }
};