// Given an m x n integers matrix, return the length of the longest increasing path in matrix.

// From each cell, you can either move in four directions: left, right, up, or down. You may not move 
// diagonally or move outside the boundary (i.e., wrap-around is not allowed).

// DFS + memo, cache on indices, compare to prev for increasing check
// Time: O(m x n)
// Space: O(m x n)

# include <vector>
# include <algorithm>
# include <map>
using namespace std;

// 20% runtime
class Solution {
public:
  int longestIncreasingPath(vector<vector<int>>& matrix) {
    int m = matrix.size();
    int n = matrix[0].size();

    int result = 0;

    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        result = max(result, dfs(matrix, -1, i, j, m, n));
      }
    }
    return result;
  }
private:
  // {(i, j) -> longest increasing path at (i, j)}
  map<pair<int, int>, int> dp;

  int dfs(vector<vector<int>>& matrix, int prev, int i, int j, int m, int n) {
    if (i < 0 || i >= m || j < 0 || j >= n || matrix[i][j] <= prev) {
      return 0;
    }
    if (dp.find({i, j}) != dp.end()) {
      return dp[{i, j}];
    }

    int result = 1;

    result = max(result, 1 + dfs(matrix, matrix[i][j], i-1, j, m, n));
    result = max(result, 1 + dfs(matrix, matrix[i][j], i+1, j, m, n));
    result = max(result, 1 + dfs(matrix, matrix[i][j], i, j-1, m, n));
    result = max(result, 1 + dfs(matrix, matrix[i][j], i, j+1, m, n));

    dp[{i, j}] = result;

    return dp[{i, j}];
  }
};


// 95% runtime
class Solution1 {
public:
  int m, n;
  short path[200][200];
  
  int longestIncreasingPath(vector<vector<int>>& matrix) {
    m = matrix.size();
    n = matrix[0].size();
    memset(path, 0, sizeof(path));
    int max_path = 1;
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        max_path = max(max_path, dfs(i, j, matrix));
      }
    }
    return max_path;
  }

  int dfs(int i, int j, vector<vector<int>>& mat) {
    if (path[i][j] > 0) {
      return path[i][j];
    }
    if (path[i][j] == -1) {
      return 0;
    }
    int max_next = 0;
    path[i][j] = -1;
    if (i > 0 && mat[i][j] < mat[i-1][j]) {
      max_next = max(max_next, dfs(i-1, j, mat));
    }
    if (j > 0 && mat[i][j] < mat[i][j-1]) {
      max_next = max(max_next, dfs(i, j-1, mat));
    }
    if (i < m-1 && mat[i][j] < mat[i+1][j]) {
      max_next = max(max_next, dfs(i+1, j, mat));
    }
    if (j < n-1 && mat[i][j] < mat[i][j+1]) {
      max_next = max(max_next, dfs(i, j+1, mat));
    }
    return path[i][j] = 1 + max_next;
  }
};

// 90% runtime easy to understand
class Solution2 {
public:
  int dp[201][201];
  int dfs(vector<vector<int>> &mat, int i, int j, int pre) {
    if (i < 0 || j < 0 || i == mat.size() || j == mat[0].size() || pre >= mat[i][j]) {
      return 0;
    }
    if (dp[i][j]) {
      return dp[i][j];
    }
    int l = dfs(mat, i, j - 1, mat[i][j]);
    int r = dfs(mat, i, j + 1, mat[i][j]);
    int u = dfs(mat, i - 1, j, mat[i][j]);
    int d = dfs(mat, i + 1, j, mat[i][j]);
    return dp[i][j] = max({l, r, u, d}) + 1;
  }
  int longestIncreasingPath(vector<vector<int>>& matrix) {
    int maxVal = 0;
    for (int i = 0; i < matrix.size(); i++) {
      for (int j = 0; j < matrix[i].size(); j++) {
        maxVal = max(maxVal, dfs(matrix, i, j, -1));
      }
    }
    return maxVal;
  }
};