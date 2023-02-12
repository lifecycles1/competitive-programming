// Given an m x n matrix, return all elements of the matrix in spiral order.

#include <vector>
using namespace std;

class Solution {
public:
  vector<int> spiralOrder(vector<vector<int>>& matrix) {
    vector<int> result;
    int m = matrix.size();

    if (m == 0) return result;

    int n = matrix[0].size();

    int left = 0, right = n-1, top = 0, bottom = m-1;
    while (left <= right && top <= bottom) {
      // traverse the top row from left to right
      for (int i = left; i <= right; i++) {
        result.push_back(matrix[top][i]);
      }
      top++;
      // traverse the right column from top to bottom
      for (int i = top; i <= bottom; i++) {
        result.push_back(matrix[i][right]);
      }
      right--;
      // traverse the bottom row from right to left (if top <= bottom)
      if (top <= bottom) {
        for (int i = right; i >= left; i--) {
          result.push_back(matrix[bottom][i]);
        }
        bottom--;
      }
      // traverse the left column from bottom to top (if left <= right)
      if (left <= right) {
        for (int i = bottom; i >= top; i--) {
          result.push_back(matrix[i][left]);
        }
        left++;
      }
    }
    return result;
  }
};