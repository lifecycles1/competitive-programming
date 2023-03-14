// The longest diagonals of a square matrix are defined as follows:

// the first longest diagonal goes from the top left corner to the bottom right one;
// the second longest diagonal goes from the top right corner to the bottom left one.
// Given a square matrix, your task is to reverse the order of elements on both of its longest diagonals.

#include <iostream>
#include <vector>

class Solution {
public:
  std::vector<std::vector<int>> reverseOnDiagonals(std::vector<std::vector<int>> matrix) {
    int n = matrix.size();
    for (int i = 0; i < n / 2; i++) {
      int temp = matrix[i][i];
      matrix[i][i] = matrix[n - i - 1][n - i - 1];
      matrix[n - i - 1][n - i - 1] = temp;
      temp = matrix[i][n - i - 1];
      matrix[i][n - i - 1] = matrix[n - i - 1][i];
      matrix[n - i - 1][i] = temp;
    }
    return matrix;
  }
};