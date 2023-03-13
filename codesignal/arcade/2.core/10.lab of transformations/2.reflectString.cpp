// Define an alphabet reflection as follows: a turns into z, b turns into y, 
// c turns into x, ..., n turns into m, m turns into n, ..., z turns into a.

// Define a string reflection as the result of applying the alphabet reflection to each of its characters.

// Reflect the given string.

#include <string>
using namespace std;

class Solution {
public:
  string reflectString(string inputString) {
    string result;
    for (auto c : inputString) {
      result += (char)('z' - (c - 'a'));
    }
    return result;
  }
};