// There is a directed graph of n nodes with each node labeled from 0 to n - 1. 
// The graph is represented by a 0-indexed 2D integer array graph where graph[i] is an 
// integer array of nodes adjacent to node i, meaning there is an edge from node i to each 
// node in graph[i].

// A node is a terminal node if there are no outgoing edges. A node is a safe node if every 
// possible path starting from that node leads to a terminal node (or another safe node).

// Return an array containing all the safe nodes of the graph. The answer should be sorted in 
// ascending order.

# include <vector>
using namespace std;

// 0 unvisited
// 1 visiting
// 2 visited
class Solution {
public:
  vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
    int n = graph.size();
    vector<int> visited(n, 0);
    vector<int> ans;
    for (int i = 0; i < n; i++) {
      if (dfs(graph, visited, i)) {
        ans.push_back(i);
      }
    }
    return ans;
  }
  
  bool dfs(vector<vector<int>>& graph, vector<int>& visited, int i) {
    if (visited[i] > 0) {
      return visited[i] == 2;
    }
    visited[i] = 1;
    for (int j : graph[i]) {
      if (!dfs(graph, visited, j)) {
        return false;
      }
    }
    visited[i] = 2;
    return true;
  }
};