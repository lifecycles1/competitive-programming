// Given an array arr, swap its first and last elements and return the resulting array.

#include <vector>

class Solution {
public:
  std::vector<int> firstReverseTry(std::vector<int> arr) {
    if (arr.size() > 1) {
      std::swap(arr.front(), arr.back());
    }
    return arr;
  }
};