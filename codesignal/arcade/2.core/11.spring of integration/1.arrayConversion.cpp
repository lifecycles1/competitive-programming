// Given an array of 2k integers (for some integer k), perform the following operations until the 
// array contains only one element:

// On the 1st, 3rd, 5th, etc. iterations (1-based) replace each pair of consecutive elements with their sum;
// On the 2nd, 4th, 6th, etc. iterations replace each pair of consecutive elements with their product.
// After the algorithm has finished, there will be a single element left in the array. Return that element.

#include <iostream>
#include <vector>

class Solution {
public:
  int arrayConversion(std::vector<int> inputArray) {
    int i = 0;
    while (inputArray.size() > 1) {
      std::vector<int> temp;
      if (i % 2 == 0) {
        for (int j = 0; j < inputArray.size(); j += 2) {
          temp.push_back(inputArray[j] + inputArray[j + 1]);
        }
      }
      else {
        for (int j = 0; j < inputArray.size(); j += 2) {
          temp.push_back(inputArray[j] * inputArray[j + 1]);
        }
      }
      inputArray = temp;
      i++;
    }
    return inputArray[0];
  }
};