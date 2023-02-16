// You are given a 0-indexed 8 x 8 grid board, where board[r][c] represents the cell (r, c) 
// on a game board. On the board, free cells are represented by '.', white cells are represented 
// by 'W', and black cells are represented by 'B'.

// Each move in this game consists of choosing a free cell and changing it to the color you are 
// playing as (either white or black). However, a move is only legal if, after changing it, 
// the cell becomes the endpoint of a good line (horizontal, vertical, or diagonal).

// A good line is a line of three or more cells (including the endpoints) where the endpoints 
// of the line are one color, and the remaining cells in the middle are the opposite color 
// (no cells in the line are free).

// Given two integers rMove and cMove and a character color representing the color you are 
// playing as (white or black), return true if changing cell (rMove, cMove) to color color 
// is a legal move, or false if it is not legal.

#include <vector>
#include <string>
using namespace std;

class Solution {
public:
  bool checkMove(vector<vector<char>>& board, int rMove, int cMove, char color) {
    int ROWS = board.size();
    int COLS = board[0].size();
    int direction[8][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}, {1, 1}, {1, -1}, {-1, 1}, {-1, -1}};
    board[rMove][cMove] = color;

    auto legal = [&](int row, int col, char color, int* dir) {
      int dr = dir[0];
      int dc = dir[1];
      row = row + dr;
      col = col + dc;
      int length = 1;

      while (0 <= row && row < ROWS && 0 <= col && col < COLS) {
        length++;
        if (board[row][col] == '.') {
          return false;
        }
        if (board[row][col] == color) {
          return length >= 3;
        }
        row = row + dr;
        col = col + dc;
      }
      return false;
    };

    for (auto d : direction) {
      if (legal(rMove, cMove, color, d)) {
        return true;
      }
    }
    return false;
  }
};