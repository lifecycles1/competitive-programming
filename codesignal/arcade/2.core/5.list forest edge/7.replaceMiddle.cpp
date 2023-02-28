// Given array arr, your task is to find its middle, and, if it consists of two elements, 
// replace those elements with the value of middle. Return the resulting array as the answer.

#include <vector>

class Solution {
public:
  std::vector<int> replaceMiddle(std::vector<int> arr) {
    if (arr.size() % 2 == 0) {
      int middle = arr[arr.size() / 2 - 1] + arr[arr.size() / 2];
      arr.erase(arr.begin() + arr.size() / 2 - 1, arr.begin() + arr.size() / 2 + 1);
      arr.insert(arr.begin() + arr.size() / 2, middle);
    }
    return arr;
  }
};