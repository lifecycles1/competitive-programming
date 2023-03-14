// You're given a substring s of some cyclic string. What's the length of the smallest possible 
// string that can be concatenated to itself many times to obtain this cyclic string?

// Example

// For s = "cabca", the output should be
// solution(s) = 3.

// "cabca" is a substring of a cycle string "abcabcabcabc..." that can be obtained by concatenating 
// "abc" to itself. Thus, the answer is 3.

#include <iostream>
#include <string>

class Solution {
public:
  int solution(std::string s) {
    for (int i = 1;; i++) {
      bool ok = true;
      for (int j = 0; j < s.size(); j++) {
        if (s[j] != s[j % i]) {
          ok = false;
          break;
        }
      }
      if (ok)
        return i;
    }
  }
};