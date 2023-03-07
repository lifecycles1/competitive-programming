// Given a string s consisting of small English letters, find and return the first instance of a
// non-repeating character in it. If there is no such character, return '_'.

// For s = "abacabad", the output should be solution(s) = 'c'.
// There are 2 non-repeating characters in the string: 'c' and 'd'.
// Return c since it appears in the string first.

// For s = "abacabaabacaba", the output should be solution(s) = '_'.
// There are no characters in this string that do not repeat.

#include <string>
#include <vector>

class Solution {
public:
  char firstNotRepeatingCharacter(std::string s) {
    std::vector<int> count(26, 0);
    for (char c : s) {
      count[c - 'a']++;
    }
    for (char c : s) {
      if (count[c - 'a'] == 1) {
        return c;
      }
    }
    return '_';
  }
};