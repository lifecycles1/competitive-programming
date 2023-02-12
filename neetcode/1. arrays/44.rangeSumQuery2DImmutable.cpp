// Given a 2D matrix matrix, handle multiple queries of the following type:

// Calculate the sum of the elements of matrix inside the rectangle defined by its upper left corner 
// (row1, col1) and lower right corner (row2, col2).
// Implement the NumMatrix class:

// NumMatrix(int[][] matrix) Initializes the object with the integer matrix matrix.
// int sumRegion(int row1, int col1, int row2, int col2) Returns the sum of the elements of matrix 
// inside the rectangle defined by its upper left corner (row1, col1) and lower right corner (row2, col2).
// You must design an algorithm where sumRegion works on O(1) time complexity.

#include <vector>
using namespace std;

class NumMatrix {
public:
  vector<vector<int>> dp;

  NumMatrix(vector<vector<int>>& matrix) {
    int r = matrix.size();
    int c = matrix[0].size();
    dp = matrix;
    for (int i = 0; i < r; i++) {
      for (int j = 0; j < c; j++) {
        if (i > 0) {
          dp[i][j] += dp[i-1][j]; // add prev row
        }
        if (j > 0) {
          dp[i][j] += dp[i][j-1]; // add prev col
        }
        if (i > 0 && j > 0) {
          dp[i][j] -= dp[i-1][j-1]; // remove diagonal as it is added twice above
        }
      }
    }
  }

  int sumRegion(int row1, int col1, int row2, int col2) {
    int answer = dp[row2][col2];

    if (row1 > 0) {
      answer -= dp[row1-1][col2]; // remove prev row on col1
    }
    if (col1 > 0) {
      answer -= dp[row2][col1-1]; // remove prev col on row2
    }
    if (row1 > 0 && col1 > 0) {
      answer += dp[row1-1][col1-1]; // add prev diagonal as prev row and prev col both contain that value
    }
    return answer;
  }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */