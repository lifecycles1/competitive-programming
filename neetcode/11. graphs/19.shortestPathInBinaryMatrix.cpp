// Given an n x n binary matrix grid, return the length of the shortest clear path in the matrix. 
// If there is no clear path, return -1.

// A clear path in a binary matrix is a path from the top-left cell (i.e., (0, 0)) 
// to the bottom-right cell (i.e., (n - 1, n - 1)) such that:

// All the visited cells of the path are 0.
// All the adjacent cells of the path are 8-directionally connected 
// (i.e., they are different and they share an edge or a corner).
// The length of a clear path is the number of visited cells of this path.

# include <vector>
# include <deque>
# include <set>
# include <tuple>
# include <utility>
# include <algorithm>
# include <queue>
using namespace std;

// slow 12% faster (good in python) solution
class Solution {
public:
  int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
    int N = grid.size();
    deque<tuple<int, int, int>> q;
    q.push_back(make_tuple(0, 0, 1)); // (row, col, length)
    set<pair<int, int>> visit;
    visit.insert(make_pair(0, 0));
    int direct[8][2] = {{-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1}};

    while (!q.empty()) {
      auto [r, c, length] = q.front();
      q.pop_front();
      if (min(r, c) < 0 || max(r, c) == N || grid[r][c]) {
        continue; // skip invalid cells
      }
      if (r == N - 1 && c == N - 1) {
        return length;
      }
      for (auto [dr, dc] : direct) {
        if (visit.find(make_pair(r + dr, c + dc)) == visit.end()) {
          q.push_back(make_tuple(r + dr, c + dc, length + 1));
          visit.insert(make_pair(r + dr, c + dc));
        }
      }
    }
    return -1;
  }
};


// 90% faster normal solution
class Solution {
public:
  int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
    // edge case: start or end not accessible
    if (grid[0][0] || grid.back().back()) return -1;
    // support variables
    int res = 2, len = 1, maxX = grid[0].size() - 1, maxY = grid.size() - 1;
    queue<pair<int, int>> q;
    // edge case: single cell matrix
    if (!maxX && !maxY) return 1 - (grid[0][0] << 1);
    // adding the starting point
    q.push({0, 0});
    // marking start as visited
    grid[0][0] = -1;
    while (len) {
      while (len--) {
        // reading and popping the coordinates on the front of the queue
        auto [cx, cy] = q.front();
        q.pop();
        for (int x = max(0, cx - 1), lmtX = min(cx + 1, maxX); x <= lmtX; x++) {
          for (int y = max(0, cy - 1), lmtY = min(cy + 1, maxY); y <= lmtY; y++) {
            // check if we reached the target
            if (x == maxX && y == maxY) return res;
            // marking it as visited and adding it to the q if it was still a valid cell
            if (!grid[y][x]) {
              grid[y][x] = -1;
              q.push({x, y});
            }
          }
        }
      }
      // preparing for the next loop
      res++;
      len = q.size();
    }
    return -1;
  }
};

// updated 100% faster geeky solution

class Solution {
  int startMark = -1, endMark = -2;
  queue<pair<int, int>> q1{{{0, 0}}}, q2;
  void markAndAdd(vector<vector<int>> &grid, int x, int y) {
    // marking the current node as visited and adding it to q
    grid[y][x] = startMark;
    q1.push({x, y});
  }
public:
  int shortestPathBinaryMatrix(vector<vector<int>> &grid) {
    int t = grid.size() - 1, res = bool(t), qLen = 1, cx, cy, x, y, currVal;
    if (grid[0][0] || grid[t][t]) return -1;
    // marking the start end end as visited
    q2.push({t, t});
    grid[0][0] = startMark;
    grid[t][t] = endMark;
    while (qLen) {
      // increasing the counter
      res++;
      while (qLen--) {
        // extracting the front of the queue
        auto &front = q1.front();
        cx = front.first;
        cy = front.second;
        // checking if we had a match
        if (grid[cy][cx] == endMark) return res;
        q1.pop();
        // adding adjacent unexplored nodes to the queue
        // diagonals:
        // upper left
        x = cx - 1, y = cy - 1;
        if (x >= 0 && y >= 0) {
          currVal = grid[y][x];
          if (currVal == endMark) return res;
          if (!currVal) markAndAdd(grid, x, y);
        }
        // upper right
        x = cx + 1;
        if (x <= t && y >= 0) {
          currVal = grid[y][x];
          if (currVal == endMark) return res;
          if (!currVal) markAndAdd(grid, x, y);
        }
        // lower right
        y = cy + 1;
        if (x <= t && y <= t) {
          currVal = grid[y][x];
          if (currVal == endMark) return res;
          if (!currVal) markAndAdd(grid, x, y);
        }
        // lower left
        x = cx - 1;
        if (x >= 0 && y <= t) {
          currVal = grid[y][x];
          if (currVal == endMark) return res;
          if (!currVal) markAndAdd(grid, x, y);
        }
        // adjacent ones:
        // mid left
        y = cy;
        if (x >= 0) {
          currVal = grid[y][x];
          if (currVal == endMark) return res;
          if (!currVal) markAndAdd(grid, x, y);
        }
        // mid right
        x = cx + 1;
        if (x <= t) {
          currVal = grid[y][x];
          if (currVal == endMark) return res;
          if (!currVal) markAndAdd(grid, x, y);
        }
        // upper mid
        x = cx, y = cy - 1;
        if (y >= 0) {
          currVal = grid[y][x];
          if (currVal == endMark) return res;
          if (!currVal) markAndAdd(grid, x, y);
        }
        // lower mid
        y = cy + 1;
        if (y <= t) {
          currVal = grid[y][x];
          if (currVal == endMark) return res;
          if (!currVal) markAndAdd(grid, x, y);
        }
      }
      swap(q1, q2);
      swap(startMark, endMark);
      qLen = q1.size();
    }
    return -1;
  }
};