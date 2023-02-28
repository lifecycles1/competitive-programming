// Given two arrays of integers a and b, obtain the array formed by 
// the elements of a followed by the elements of b.

#include <vector>

class Solution {
public:
  std::vector<int> concatenateArrays(std::vector<int> a, std::vector<int> b) {
    a.insert(a.end(), b.begin(), b.end());
    return a;
  }
};