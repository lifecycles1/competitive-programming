// You are given an integer array cost where cost[i] is the cost of ith step on a staircase. 
// Once you pay the cost, you can either climb one or two steps.

// You can either start from the step with index 0, or the step with index 1.

// Return the minimum cost to reach the top of the floor

#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
  int minCostClimbingStairs(vector<int>& cost) {
    int downOne = 0;
    int downTwo = 0;

    for (int i = 2; i <= cost.size(); i++) {
      int temp = downOne;
      downOne = min(downOne + cost[i-1], downTwo + cost[i-2]);
      downTwo= temp;
    }
    return downOne;
  }
};