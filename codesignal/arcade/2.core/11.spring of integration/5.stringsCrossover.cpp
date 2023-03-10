// Define crossover operation over two equal-length strings A and B as follows:

// the result of that operation is a string of the same length as the input strings
// result[i] is either A[i] or B[i], chosen at random
// Given array of strings inputArray and a string result, find for how many pairs of strings 
// from inputArray the result of the crossover operation over them may be equal to result.

// Note that (A, B) and (B, A) are the same pair. Also note that the pair cannot include the same element 
// of the array twice (however, if there are two equal elements in the array, they can form a pair).

#include <iostream>
#include <string>
#include <vector>

class Solution {
public:
  int stringsCrossover(std::vector<std::string> inputArray, std::string result) {
    int r = 0;
    for (int i = 0; i < inputArray.size(); i++) {
      for (int j = i + 1; j < inputArray.size(); j++) {
        bool ok = true;
        for (int k = 0; k < result.length(); k++) {
          if (inputArray[i][k] != result[k] && inputArray[j][k] != result[k]) {
            ok = false;
            break;
          }
        }
        if (ok) r++;
      }
    }
    return r;
  }
};