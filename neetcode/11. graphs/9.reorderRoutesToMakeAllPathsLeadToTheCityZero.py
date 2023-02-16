# There are n cities numbered from 0 to n - 1 and n - 1 roads such that there is only one way to travel between two 
# different cities (this network form a tree). Last year, The ministry of transport decided to orient the roads in one 
# direction because they are too narrow.

# Roads are represented by connections where connections[i] = [ai, bi] represents a road from city ai to city bi.

# This year, there will be a big event in the capital (city 0), and many people want to travel to this city.

# Your task consists of reorienting some roads such that each city can visit the city 0. Return the minimum number of edges changed.

# It's guaranteed that each city can reach city 0 after reorder.

from typing import List

class Solution:
  def minReorder(self, n: int, connections: List[List[int]]) -> int:
    graph = [[] for _ in range(n)]
    for c in connections:
      graph[c[0]].append(c[1])
      graph[c[1]].append(-c[0])
    ans = [0]
    visited = [False] * n
    self.dfs(graph, 0, visited, ans)
    return ans[0]
  
  def dfs(self, graph: List[List[int]], node: int, visited: List[bool], ans: List[int]) -> None:
    visited[node] = True
    for i in graph[node]:
      if visited[abs(i)]:
        continue
      if i > 0:
        ans[0] += 1
      self.dfs(graph, abs(i), visited, ans)
