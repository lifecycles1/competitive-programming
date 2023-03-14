// Given a rectangular matrix and an integer column, return an array containing the elements of 
// the columnth column of the given matrix (the leftmost column is the 0th one).

#include <iostream>
#include <vector>

class Solution {
public:
  std::vector<int> extractMatrixColumn(std::vector<std::vector<int>> matrix, int column) {
    std::vector<int> result;
    for (int i = 0; i < matrix.size(); i++) {
      result.push_back(matrix[i][column]);
    }
    return result;
  }
};