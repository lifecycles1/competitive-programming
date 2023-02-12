// You are given an array points representing integer coordinates of some points on a 2D-plane, 
// where points[i] = [xi, yi].

// The cost of connecting two points [xi, yi] and [xj, yj] is the manhattan distance between them: 
// |xi - xj| + |yi - yj|, where |val| denotes the absolute value of val.

// Return the minimum cost to make all points connected. All points are connected if there is exactly 
// one simple path between any two points.

// Given array of points, return min cost to connect all points
// All points have 1 path b/w them, cost is Manhattan distance
// MST problem, Prim's, greedily pick node not in MST & has smallest edge cost
// Add to MST, & for all its neighbors, try to update min dist values, repeat
// Time: O(n^2)
// Space: O(n)

// The code implements a greedy algorithm to find the minimum spanning tree (MST) of a graph represented 
// by the input points. The result of the algorithm is the sum of the minimum distances stored in minDist.

#include <vector>
using namespace std;

class Solution {
public:
  int minCostConnectPoints(vector<vector<int>>& points) {
    int n = points.size();

    int edgesUsed = 0;
    // track visited nodes
    vector<bool> inMST(n);
    vector<int> minDist(n, INT_MAX);
    minDist[0] = 0;

    int result = 0;

    while (edgesUsed < n) {
      int currMinEdge = INT_MAX;
      int currNode = -1;

      //greedily pick lowest cost node not in MST
      for (int i = 0; i < n; i++) {
        if (!inMST[i] && currMinEdge > minDist[i]) {
          currMinEdge = minDist[i];
          currNode = i;
        }
      }

      result += currMinEdge;
      edgesUsed++;
      inMST[currNode] = true;

      // update adj nodes of curr node
      for (int i = 0; i < n; i++) {
        int cost = abs(points[currNode][0] - points[i][0]) + abs(points[currNode][1] - points[i][1]);
        if (!inMST[i] && minDist[i] > cost) {
          minDist[i] = cost;
        }
      }
    }
    return result;
  }
};