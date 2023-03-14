// The longest diagonals of a square matrix are defined as follows:

// the first longest diagonal goes from the top left corner to the bottom right one;
// the second longest diagonal goes from the top right corner to the bottom left one.
// Given a square matrix, your task is to swap its longest diagonals by exchanging their elements 
// at the corresponding positions.

#include <iostream>
#include <vector>

class Solution {
public:
  std::vector<std::vector<int>> swapDiagonals(std::vector<std::vector<int>> matrix) {
    int n = matrix.size();
    for (int i = 0; i < n; i++) {
      int temp = matrix[i][i];
      matrix[i][i] = matrix[i][n - i - 1];
      matrix[i][n - i - 1] = temp;
    }
    return matrix;
  }
};