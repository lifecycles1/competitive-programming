// You are given an n x n integer matrix board where the cells are labeled 
// from 1 to n2 in a Boustrophedon style starting from the bottom left of the board 
// (i.e. board[n - 1][0]) and alternating direction each row.

// You start on square 1 of the board. In each move, starting from square curr, do the following:

// Choose a destination square next with a label in the range [curr + 1, min(curr + 6, n2)].
// This choice simulates the result of a standard 6-sided die roll: i.e., there are always 
// at most 6 destinations, regardless of the size of the board.
// If next has a snake or ladder, you must move to the destination of that snake or ladder. 
// Otherwise, you move to next.
// The game ends when you reach the square n2.
// A board square on row r and column c has a snake or ladder if board[r][c] != -1. 
// The destination of that snake or ladder is board[r][c]. Squares 1 and n2 do not have 
// a snake or ladder.

// Note that you only take a snake or ladder at most once per move. If the destination 
// to a snake or ladder is the start of another snake or ladder, you do not follow the 
// subsequent snake or ladder.

// For example, suppose the board is [[-1,4],[-1,3]], and on the first move, your destination 
// square is 2. You follow the ladder to square 3, but do not follow the subsequent ladder to 4.
// Return the least number of moves required to reach the square n2. If it is not possible to 
// reach the square, return -1.

#include <vector>
#include <deque>
#include <unordered_set>
#include <algorithm>

class Solution {
public:
  int snakesAndLadders(std::vector<std::vector<int>>& board) {
    int length = board.size();
    std::reverse(board.begin(), board.end());

    auto intToPos = [&](int square) -> std::pair<int, int> {
      int r = (square - 1) / length;
      int c = (square - 1) % length;
      if (r % 2 == 1) {
        c = length - 1 - c;
      }
      return std::make_pair(r, c);
    };

    std::deque<std::pair<int, int>> q;
    q.push_back(std::make_pair(1, 0)); // [square, moves]
    std::unordered_set<int> visit;
    while (!q.empty()) {
      auto [square, moves] = q.front();
      q.pop_front();

      for (int i = 1; i <= 6; i++) {
        int nextSquare = square + i;
        auto [r, c] = intToPos(nextSquare);
        if (board[r][c] != -1) {
          nextSquare = board[r][c];
        }
        if (nextSquare == length * length) {
          return moves + 1;
        }
        if (visit.find(nextSquare) == visit.end()) {
          visit.insert(nextSquare);
          q.push_back(std::make_pair(nextSquare, moves + 1));
        }
      }
    }

    return -1;
  }
};