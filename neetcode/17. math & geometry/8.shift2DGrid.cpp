// Given a 2D grid of size m x n and an integer k. You need to shift the grid k times.

// In one shift operation:

// Element at grid[i][j] moves to grid[i][j + 1].
// Element at grid[i][n - 1] moves to grid[i + 1][0].
// Element at grid[m - 1][n - 1] moves to grid[0][0].
// Return the 2D grid after applying shift operation k times.

#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> res(m, vector<int>(n));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int x = (i * n + j + k) % (m * n);
                res[x / n][x % n] = grid[i][j];
            }
        }
        return res;
    }
};

class Solution {
public:
  vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
    int M = grid.size();
    int N = grid[0].size();

    auto posToVal = [&](int r, int c) -> int {
      return r * N + c;
    };
    auto valToPos = [&](int v) -> pair<int, int> {
      return {v / N, v % N}; // {r, c}
    };

    vector<vector<int>> res(M, vector<int>(N, 0));
    for (int r = 0; r < M; r++) {
      for (int c = 0; c < N; c++) {
        int newVal = (posToVal(r, c) + k) % (M * N);
        auto [newR, newC] = valToPos(newVal);
        res[newR][newC] = grid[r][c];
      }
    }

    return res;
  }
};