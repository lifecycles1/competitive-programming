// Given an array of strings, sort them in the order of increasing lengths. 
// If two strings have the same length, their relative order must be the same as in the initial array.

#include <vector>
#include <string>
#include <algorithm>

class Solution {
public:
  std::vector<std::string> sortByLength(std::vector<std::string> inputArray) {
    std::sort(inputArray.begin(), inputArray.end(), [](std::string a, std::string b) {
      return a.size() < b.size();
    });
    return inputArray;
  }
};

class Solution {
public:
  std::vector<std::string> sortByLength(std::vector<std::string> inputArray) {
    // implement insertion sort algorithm
    for (int i = 1; i < inputArray.size(); i++) {
      std::string key = inputArray[i];
      int j = i - 1;
      while (j >= 0 && inputArray[j].size() > key.size()) {
        inputArray[j + 1] = inputArray[j];
        j--;
      }
      inputArray[j + 1] = key;
    }
    return inputArray;
  }
};