// Given a positive integer number and a certain length, we need to modify the given number to have 
// a specified length. We are allowed to do that either by cutting out leading digits 
// (if the number needs to be shortened) or by adding 0s in front of the original number.

#include <string>
using namespace std;

class Solution {
public:
  string integerToStringOfFixedWidth(int number, int width) {
    string s = to_string(number);
    if (s.size() < width) {
      s = string(width - s.size(), '0') + s;
    } else if (s.size() > width) {
      s = s.substr(s.size() - width);
    }
    return s;
  }
};