// The n-queens puzzle is the problem of placing n queens on an n x n chessboard such 
// that no two queens attack each other.

// Given an integer n, return the number of distinct solutions to the n-queens puzzle.

#include <set>

class Solution {
public:
  int totalNQueens(int n) {
    backtrack(0, n);
    return answer;
  }
private:
  int answer = 0;
  std::set<int> cols;
  std::set<int> posdiag;
  std::set<int> negdiag;
  void backtrack(int i, int n) {
    if (i == n) {
      answer++;
      return;
    }

    for (int j = 0; j < n; j++) {
      if (cols.find(j) != cols.end() || posdiag.find(i+j) != posdiag.end() || negdiag.find(i-j) != negdiag.end()) {
        continue;
      }

      cols.insert(j);
      posdiag.insert(i+j);
      negdiag.insert(i-j);

      backtrack(i+1, n);

      cols.erase(j);
      posdiag.erase(i+j);
      negdiag.erase(i-j);
    }
  }
};