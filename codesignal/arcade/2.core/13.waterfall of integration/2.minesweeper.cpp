// In the popular Minesweeper game you have a board with some mines and those cells that don't contain 
// a mine have a number in it that indicates the total number of mines in the neighboring cells. 
// Starting off with some arrangement of mines we want to create a Minesweeper game setup.

// Example

// For

// matrix = [[true, false, false],
//           [false, true, false],
//           [false, false, false]]
// the output should be

// solution(matrix) = [[1, 2, 1],
//                     [2, 1, 1],
//                     [1, 1, 1]]

#include <iostream>
#include <vector>

class Solution {
public:
    std::vector<std::vector<int>> minesweeper(std::vector<std::vector<bool>> matrix) {
        std::vector<std::vector<int>> result;
        for (int i = 0; i < matrix.size(); i++) {
            std::vector<int> row;
            for (int j = 0; j < matrix[i].size(); j++) {
                int count = 0;
                if (i > 0) {
                    if (j > 0) {
                        if (matrix[i - 1][j - 1]) {
                            count++;
                        }
                    }
                    if (matrix[i - 1][j]) {
                        count++;
                    }
                    if (j < matrix[i].size() - 1) {
                        if (matrix[i - 1][j + 1]) {
                            count++;
                        }
                    }
                }
                if (j > 0) {
                    if (matrix[i][j - 1]) {
                        count++;
                    }
                }
                if (j < matrix[i].size() - 1) {
                    if (matrix[i][j + 1]) {
                        count++;
                    }
                }
                if (i < matrix.size() - 1) {
                    if (j > 0) {
                        if (matrix[i + 1][j - 1]) {
                            count++;
                        }
                    }
                    if (matrix[i + 1][j]) {
                        count++;
                    }
                    if (j < matrix[i].size() - 1) {
                        if (matrix[i + 1][j + 1]) {
                            count++;
                        }
                    }
                }
                row.push_back(count);
            }
            result.push_back(row);
        }
        return result;
    }
};