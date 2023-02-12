// You are given an n x n integer matrix grid where each value grid[i][j] represents the elevation 
// at that point (i, j).

// The rain starts to fall. At time t, the depth of the water everywhere is t. You can swim from a 
// square to another 4-directionally adjacent square if and only if the elevation of both squares 
// individually are at most t. You can swim infinite distances in zero time. Of course, you must 
// stay within the boundaries of the grid during your swim.

// Return the least time until you can reach the bottom right square (n - 1, n - 1) if you start at 
// the top left square (0, 0).

// Given an integer elevation matrix, rain falls, at time t, depth everywhere is t
// Can swim iff elevation at most t, return least time get from top left to bottom right
// Modified Dijkstra's Shortest path w/ min heap: at every step, find lowest water level to move forward
// Time: O(n^2 log n)
// Space: O(n^2)

#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
  int swimInWater(vector<vector<int>>& grid) {
    int n = grid.size();
    if (n == 1) {
      return 0;
    }

    vector<vector<bool>> visited(n, vector<bool>(n));
    visited[0][0] = true;

    int result = max(grid[0][0], grid[n-1][n-1]);

    priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
    pq.push({result, 0, 0});

    while (!pq.empty()) {
      vector<int> curr = pq.top();
      pq.pop();

      result = max(result, curr[0]);

      for (int i = 0; i < 4; i++) {
        int x = curr[1] + dirs[i][0];
        int y = curr[2] + dirs[i][1];

        if (x < 0 || x >= n || y < 0 || y >= n || visited[x][y]) {
          continue;
        }

        if (x == n-1 && y == n-1){
          return result;
        }

        pq.push({grid[x][y], x, y});
        visited[x][y] = true;
      }
    }
    return -1;
  }
private:
  vector<vector<int>> dirs = {{-1, 0}, {1, 0}, {0, -1} , {0, 1}};
};