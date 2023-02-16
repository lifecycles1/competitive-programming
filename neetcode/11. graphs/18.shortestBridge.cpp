// You are given an n x n binary matrix grid where 1 represents land and 0 represents water.

// An island is a 4-directionally connected group of 1's not connected to any other 1's. 
// There are exactly two islands in grid.

// You may change 0's to 1's to connect the two islands to form one island.

// Return the smallest number of 0's you must flip to connect the two islands.

#include <vector>
#include <list>
using namespace std;

class Solution {
public:
    int paint(vector<vector<int>>& A, int i, int j) {
      if (min(i, j) < 0 || max(i, j) == A.size() || A[i][j] != 1)
        return 0;
      A[i][j] = 2;
      return 1 + paint(A, i + 1, j) + paint(A, i - 1, j) + paint(A, i, j + 1) + paint(A, i, j - 1);
    }

    bool expand(vector<vector<int>>& A, int i, int j, int cl) {
      if (min(i, j) < 0 || max(i, j) == A.size())
        return false;
      A[i][j] = A[i][j] == 0 ? cl + 1 : A[i][j];
      return A[i][j] == 1;
    } 

    int shortestBridge(vector<vector<int>>& A) {
      for (int i = 0, found = 0; !found && i < A.size(); ++i)
        for (int j = 0; !found && j < A[0].size(); ++j)
          found = paint(A, i, j);
      for (int cl = 2; ; ++cl)
        for (int i = 0; i < A.size(); ++i)
          for (int j = 0; j < A.size(); ++j) 
            if (A[i][j] == cl && ((expand(A, i - 1, j, cl) || expand(A, i, j - 1, cl) || 
              expand(A, i + 1, j, cl) || expand(A, i, j + 1, cl))))
                return cl - 2;
    }
};

// Same idea, but using a queue instead of scaning the grid.
class Solution {
public:
  int dir[5] = {0, 1, 0, -1, 0};

  void paint(vector<vector<int>>& A, int i, int j, vector<pair<int, int>> &q) {
    if (min(i, j) >= 0 && max(i, j) < A.size() && A[i][j] == 1) {
      A[i][j] = 2;
      q.push_back({i, j});
      for (int d = 0; d < 4; ++d)
        paint(A, i + dir[d], j + dir[d + 1], q);
    }
  }

  int shortestBridge(vector<vector<int>>& A) {
    vector<pair<int, int>> q;
    for (int i = 0; q.size() == 0 && i < A.size(); ++i)
      for (int j = 0; q.size() == 0 && j < A[0].size(); ++j)
        paint(A, i, j, q);
    while (!q.empty()) {
      vector<pair<int, int>> q1;
      for (auto [i, j] : q) {
        for (int d = 0; d < 4; ++d) {
          int x = i + dir[d], y = j + dir[d + 1];
          if (min(x, y) >= 0 && max(x, y) < A.size()) {
            if (A[x][y] == 1)
              return A[i][j] - 2;
            if (A[x][y] == 0) {
              A[x][y] = A[i][j] + 1;
              q1.push_back({x, y});
            }
          }
        }
      }
      swap(q, q1);
    }
    return 0;
  }
};

// union-find based solution. slower but more complex, plus it has extra data structures to be studied.
class Solution {
public:
  int uf_find(int i, vector<int>& nodes) {
    if (nodes[i] <= 0) return i;
    else return nodes[i] = uf_find(nodes[i], nodes);
  }

  int uf_union(int i, int j, vector<int>& nodes) {
    auto pi = uf_find(i, nodes), pj = uf_find(j, nodes);
    if (pi == pj) return 0;
    if (nodes[pi] > nodes[pj]) swap(pi, pj);
    nodes[pi] += min(-1, nodes[pj]);
    nodes[pj] = pi;
    return -nodes[pi];
  }

  int shortestBridge(vector<vector<int>> &A) {
    int sz = A.size();
    vector<int> nodes(sz * sz + 1);
    list<pair<int, int>> edges;
    for (auto i = 0; i < sz; ++i)
      for (auto j = 0; j < sz; ++j) {
        auto idx = i * sz + j + 1;
        if (A[i][j]) nodes[idx] = -1;
        if (j > 0) {
          if (A[i][j] && A[i][j - 1]) uf_union(idx - 1, idx, nodes);
          else edges.push_back({ idx - 1, idx });
        }
        if (i > 0) {
          if (A[i][j] && A[i - 1][j]) uf_union(idx - sz, idx, nodes);
          else edges.push_back({ idx - sz, idx });
        }
      }

    for (auto step = 1; ; ++step) {
      vector<pair<int, int>> merge_list;
      for (auto it = edges.begin(); it != edges.end(); ) {
        if (nodes[it->first] == 0 && nodes[it->second] == 0) ++it;
        else {
          if (nodes[it->first] != 0 && nodes[it->second] != 0) {
            if (uf_find(it->first, nodes) != uf_find(it->second, nodes)) return (step - 1) * 2;
          }
          merge_list.push_back({ it->first, it->second });
          edges.erase(it++);
        }
      }
      for (auto p : merge_list) {
        if (nodes[p.first] != 0 && nodes[p.second] != 0) {
          if (uf_find(p.first, nodes) != uf_find(p.second, nodes)) return step * 2 - 1;
        }
        uf_union(p.first, p.second, nodes);
      }
    }
  }
};