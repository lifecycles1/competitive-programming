// Given an integer size, return array of length size filled with 1s.

#include <vector>

class Solution {
public:
  std::vector<int> createArray(int size) {
    return std::vector<int>(size, 1);
  }
};