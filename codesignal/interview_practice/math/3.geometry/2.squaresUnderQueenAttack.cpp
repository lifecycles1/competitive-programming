// Note: Write a solution with O(queries.length + queens.length + n) complexity and 
// O(queries.length) additional memory, since this is what you would be asked to do during a 
// real interview.

// In chess, queens can move any number of squares vertically, horizontally, or diagonally. 
// You have an n × n chessboard with some queens on it. You are given several queries, each of 
// which represents one square on the chessboard. For each query square, determine whether it 
// can be attacked by a queen or not.

#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
  vector<bool> squaresUnderQueenAttack(int n, vector<vector<int>> queens, vector<vector<int>> queries) {
    unordered_set<int> rows, cols, diags1, diags2;
    for (auto& q: queens) {
      int r = q[0], c = q[1];
      rows.insert(r);
      cols.insert(c);
      diags1.insert(r + c);
      diags2.insert(r - c);
    }

    vector<bool> result;
    for (auto& q : queries) {
      int r = q[0], c = q[1];
      bool attacked = (rows.count(r) || cols.count(c) || diags1.count(r + c) || diags2.count(r - c));
      result.push_back(attacked);
    }
    return result;
  }
};