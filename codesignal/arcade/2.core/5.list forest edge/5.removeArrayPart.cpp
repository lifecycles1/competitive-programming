// Remove a part of a given array between given 0-based indexes l and r (inclusive).

#include <vector>

class Solution {
public:
  std::vector<int> removeArrayPart(std::vector<int> inputArray, int l, int r) {
    inputArray.erase(inputArray.begin() + l, inputArray.begin() + r + 1);
    return inputArray;
  }
};