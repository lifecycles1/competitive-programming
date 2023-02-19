# You are given an undirected weighted graph of n nodes (0-indexed), 
# represented by an edge list where edges[i] = [a, b] is an undirected edge connecting 
# the nodes a and b with a probability of success of traversing that edge succProb[i].

# Given two nodes start and end, find the path with the maximum probability of success to go 
# from start to end and return its success probability.

# If there is no path from start to end, return 0. Your answer will be accepted if it differs 
# from the correct answer by at most 1e-5.

from typing import List
from collections import defaultdict
from heapq import heappush, heappop

# Dijkstra's algorithm with a max heap
class Solution:
    def maxProbability(self, n: int, edges: List[List[int]], succProb: List[float], start: int, end: int) -> float:
        graph = defaultdict(list)
        for i, edge in enumerate(edges):
            graph[edge[0]].append((edge[1], succProb[i]))
            graph[edge[1]].append((edge[0], succProb[i]))
        heap = [(-1, start)]
        visited = set()
        while heap:
            prob, node = heappop(heap)
            if node == end:
                return -prob
            if node in visited:
                continue
            visited.add(node)
            for neighbor, neighbor_prob in graph[node]:
                heappush(heap, (prob * neighbor_prob, neighbor))
        return 0