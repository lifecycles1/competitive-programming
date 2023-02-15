// The n-queens puzzle is the problem of placing n queens on an n x n chessboard such that no two 
// queens attack each other.

// Given an integer n, return all distinct solutions to the n-queens puzzle. You may return the 
// answer in any order.

// Each solution contains a distinct board configuration of the n-queens' placement, where 'Q' and '.' 
// both indicate a queen and an empty space, respectively.

// Place queens per row, try all possibilities & validate for further rows, backtrack
// Time: O(n!)
// Space: O(n^2)

# include <unordered_set>
# include <vector>
# include <string>
using namespace std;

class Solution {
private:
  unordered_set<int> cols; //for columns
  unordered_set<int> negDiag; // for negative diagonals R-C
  unordered_set<int> posDiag; // for positive diagonals R+C

  void backtrack(int n, int row, vector<vector<string>>& res, vector<string>&board) {
    if (row == n) {
      res.push_back(board);
      return;
    }
    for (int col = 0; col < n; col++) { // shifting through each col
      if (cols.find(col) != cols.end() || //if queen already placed in this col
          negDiag.find(row - col) != negDiag.end() || // if queen in negDiag
          posDiag.find(row + col) != posDiag.end()
      ) {
        continue; // skip this col
      }

      cols.insert(col);
      negDiag.insert(row-col);
      posDiag.insert(row+col);
      board[row][col] = 'Q';
      backtrack(n, row+1, res, board);

      cols.erase(col);
      negDiag.erase(row-col);
      posDiag.erase(row+col);
      board[row][col] = '.';
    }
  }
public:
  vector<vector<string>> solveNQueens(int n) {
    vector<vector<string>> res;
    vector<string> board(n, string(n, '.'));
    backtrack(n, 0, res, board);
    return res;
  }
};