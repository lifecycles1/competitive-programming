// Given a rectangular matrix containing only digits, calculate the number of different 
// 2 × 2 squares in it.

#include <set>
#include <vector>
#include <utility>

class Solution {
public:
  int differentSquares(std::vector<std::vector<int>> matrix) {
    std::set<std::pair<int, int>> r;
    for (int i = 0; i < matrix.size() - 1; ++i)
      for (int j = 0; j < matrix[i].size() - 1; ++j)
        r.insert({matrix[i][j] * 1000 + matrix[i][j + 1] * 100 + matrix[i + 1][j] * 10 + matrix[i + 1][j + 1], 0});
    return r.size();
  }
};