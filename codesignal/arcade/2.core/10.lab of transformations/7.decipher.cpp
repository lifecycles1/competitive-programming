// Consider the following ciphering algorithm:

// For each character replace it with its code.
// Concatenate all of the obtained numbers.
// Given a ciphered string, return the initial one if it is known that it consists only of lowercase 
// letters.

// Note: here the character's code means its decimal ASCII code, the numerical representation of a 
// character used by most modern programming languages.

// Example

// For cipher = "10197115121", the output should be
// solution(cipher) = "easy".

#include <string>

class Solution {
public:
    std::string solution(std::string cipher) {
      std::string r;
      for (int i = 0; i < cipher.size();) {
          int l = cipher[i] == '1' ? 3 : 2;
          r += (char)stoi(cipher.substr(i, l));
          i += l;
      }
      return r;
    }
};