// Given a rectangular matrix and integers a and b, consider the union of the ath row and the bth 
// (both 0-based) column of the matrix (i.e. all cells that belong either to the ath row or to the bth 
// column, or to both). Return sum of all elements of that union.

#include <iostream>
#include <vector>

class Solution {
public:
  int crossingSum(std::vector<std::vector<int>> matrix, int a, int b) {
    int sumA = 0;
    int sumB = 0;
    for (int i = 0; i < matrix.size(); i++) {
      sumA += matrix[a][i];
    }
    for (int i = 0; i < matrix.size(); i++) {
      sumB += matrix[i][b];
    }
    return sumA + sumB - matrix[a][b];
  }
};