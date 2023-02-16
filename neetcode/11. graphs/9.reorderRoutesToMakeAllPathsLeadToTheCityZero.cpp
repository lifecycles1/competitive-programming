// There are n cities numbered from 0 to n - 1 and n - 1 roads such that there is only one way to travel between two 
// different cities (this network form a tree). Last year, The ministry of transport decided to orient the roads in one 
// direction because they are too narrow.

// Roads are represented by connections where connections[i] = [ai, bi] represents a road from city ai to city bi.

// This year, there will be a big event in the capital (city 0), and many people want to travel to this city.

// Your task consists of reorienting some roads such that each city can visit the city 0. Return the minimum number of edges changed.

// It's guaranteed that each city can reach city 0 after reorder.

#include <vector>
using namespace std;

class Solution {
public:
  int minReorder(int n, vector<vector<int>>& connections) {
    vector<vector<int>> graph(n);
    for (auto& c : connections) {
      graph[c[0]].push_back(c[1]);
      graph[c[1]].push_back(-c[0]);
    }
    int ans = 0;
    vector<bool> visited(n);
    dfs(graph, 0, visited, ans);
    return ans;
  }
private:
  void dfs(vector<vector<int>>& graph, int node, vector<bool>& visited, int& ans) {
    visited[node] = true;
    for (int i : graph[node]) {
      if (visited[abs(i)]) {
        continue;
      }
      if (i > 0) {
        ans++;
      }
      dfs(graph, abs(i), visited, ans);
    }
  }
};