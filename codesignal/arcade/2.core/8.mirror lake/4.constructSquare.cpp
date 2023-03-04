// Given a string consisting of lowercase English letters, find the largest square number which 
// can be obtained by reordering the string's characters and replacing them with any digits you need 
// (leading zeros are not allowed) where same characters always map to the same digits and 
// different characters always map to different digits.

// If there is no solution, return -1.

#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
  int constructSquare(std::string s) {
    auto sortedHistogram = [](const auto& t, const auto base) {
      vector h(26, 0);
      for (auto x : t) ++h[x-base];
      sort(begin(h), end(h));
      return h;
    };
    
    auto hs = sortedHistogram(s, 'a');
    
    int hi2 = pow(10, size(s)), largest = -1;
    for (int i = pow(10, .5 * (size(s)-1)); i*i < hi2; ++i)
      if (hs == sortedHistogram(to_string(i*i), '0'))
        largest = i*i;
    
    return largest;
  }
};