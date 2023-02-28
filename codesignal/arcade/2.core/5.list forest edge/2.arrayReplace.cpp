// Given an array of integers, replace all the occurrences of elemToReplace with substitutionElem.

#include <vector>

class Solution {
public:
  std::vector<int> arrayReplace(std::vector<int> inputArray, int elemToReplace, int substitutionElem) {
    for (auto& i : inputArray) {
      if (i == elemToReplace) {
        i = substitutionElem;
      }
    }
    return inputArray;
  }
};