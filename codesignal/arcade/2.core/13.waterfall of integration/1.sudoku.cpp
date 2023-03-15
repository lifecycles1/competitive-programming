// Sudoku is a number-placement puzzle. The objective is to fill a 9 × 9 grid with digits so that 
// each column, each row, and each of the nine 3 × 3 sub-grids that compose the grid contains all of 
// the digits from 1 to 9.

// This algorithm should check if the given grid of numbers represents a correct solution to Sudoku.

// Example

// For
// grid = [[1, 3, 2, 5, 4, 6, 9, 8, 7],
//         [4, 6, 5, 8, 7, 9, 3, 2, 1],
//         [7, 9, 8, 2, 1, 3, 6, 5, 4],
//         [9, 2, 1, 4, 3, 5, 8, 7, 6],
//         [3, 5, 4, 7, 6, 8, 2, 1, 9],
//         [6, 8, 7, 1, 9, 2, 5, 4, 3],
//         [5, 7, 6, 9, 8, 1, 4, 3, 2],
//         [2, 4, 3, 6, 5, 7, 1, 9, 8],
//         [8, 1, 9, 3, 2, 4, 7, 6, 5]]
// the output should be
// solution(grid) = true;

// For
// grid = [[8, 3, 6, 5, 3, 6, 7, 2, 9],
//         [4, 2, 5, 8, 7, 9, 3, 8, 1],
//         [7, 9, 1, 2, 1, 4, 6, 5, 4],
//         [9, 2, 1, 4, 3, 5, 8, 7, 6],
//         [3, 5, 4, 7, 6, 8, 2, 1, 9],
//         [6, 8, 7, 1, 9, 2, 5, 4, 3],
//         [5, 7, 6, 9, 8, 1, 4, 3, 2],
//         [2, 4, 3, 6, 5, 7, 1, 9, 8],
//         [8, 1, 9, 3, 2, 4, 7, 6, 5]]
// the output should be
// solution(grid) = false.

#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
  bool sudoku(vector<vector<int>> grid) {
    // check rows
    for (auto row: grid) {
      unordered_set<int> seen;
      for (auto num: row) {
        if (seen.find(num) != seen.end()) {
          return false;
        }
        seen.insert(num);
      }
    }
    // check columns
    for (int i = 0; i < grid.size(); i++) {
      unordered_set<int> seen;
      for (int j = 0; j < grid.size(); j++) {
        if (seen.find(grid[j][i]) != seen.end()) {
          return false;
        }
        seen.insert(grid[j][i]);
      }
    }
    // check 3x3 subgrids
    for (int i = 0; i < grid.size(); i += 3) {
      for (int j = 0; j < grid.size(); j += 3) {
        unordered_set<int> seen;
        for (int k = i; k < i + 3; k++) {
          for (int l = j; l < j + 3; l++) {
            if (seen.find(grid[k][l]) != seen.end()) {
              return false;
            }
            seen.insert(grid[k][l]);
          }
        }
      }
    }
    return true;
  }
};