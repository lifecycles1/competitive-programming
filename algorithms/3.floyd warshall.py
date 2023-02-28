# Floyd-Warshall's algorithm is a dynamic programming algorithm used to find the shortest path 
# between all pairs of vertices in a weighted graph. It works by finding the shortest path between 
# every pair of vertices in a graph, taking into account the weights of the edges between them.

class Solution:
    def floydWarshall(self, graph):
        n = len(graph)
        for k in range(n):
            for i in range(n):
                for j in range(n):
                    graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j])
        return graph