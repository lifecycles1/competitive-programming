// Given an m x n matrix board containing 'X' and 'O', capture all regions that are 4-directionally 
// surrounded by 'X'.

// A region is captured by flipping all 'O's into 'X's in that surrounded region.


// Given a matrix, capture ('X') all regions that are surrounded ('O')
// Distinguish captured vs escaped, 'X' vs 'O' vs 'E'
// Time: O(m x n)
// Space: O(m x n)

#include <vector>
using namespace std;

class Solution {
public:
  void solve(vector<vector<char>>& board) {
    int m = board.size();
    int n = board[0].size();

    // marking escaped cells along the border
    for (int i = 0; i < m; i++) {
      dfs(board, i, 0, m, n);
      dfs(board, i, n-1, m, n);
    }
    for (int j = 0; j < n; j++) {
      dfs(board, 0, j, m, n);
      dfs(board, m-1, j, m, n);
    }
    // flip cells to correct final states
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        if (board[i][j] == 'O') {
          board[i][j] = 'X';
        }
        if (board[i][j] == 'E') {
          board[i][j] = 'O';
        }
      }
    }
  }
private:
  void dfs(vector<vector<char>>& board, int i, int j, int m, int n) {
    if (i < 0 || i >= m || j < 0 || j >= n || board[i][j] != 'O') {
      return;
    }
    board[i][j] = 'E';

    dfs(board, i-1, j, m, n);
    dfs(board, i+1, j, m, n);
    dfs(board, i, j-1, m, n);
    dfs(board, i, j+1, m, n);
  }
};