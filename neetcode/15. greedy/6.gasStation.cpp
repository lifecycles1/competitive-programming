// There are n gas stations along a circular route, where the amount of gas at the ith station is gas[i].

// You have a car with an unlimited gas tank and it costs cost[i] of gas to travel from the ith station 
// to its next (i + 1)th station. You begin the journey with an empty tank at one of the gas stations.

// Given two integer arrays gas and cost, return the starting gas station's index if you can travel 
// around the circuit once in the clockwise direction, otherwise return -1. If there exists a solution, 
// it is guaranteed to be unique

// At a start station, if total ever becomes negative won't work, try next station
// Time: O(n)
// Space: O(1)

#include <vector>
using namespace std;

class Solution {
public:
  int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
    int n = gas.size();

    int totalGas = 0;
    int totalCost = 0;
    for (int i = 0; i < n; i++) {
      totalGas += gas[i];
      totalCost += cost[i];
    }
    if (totalGas < totalCost) {
      return -1;
    }
    int total = 0;
    int result = 0;

    for (int i = 0; i < n; i++) {
      total += gas[i] - cost[i];
      if (total < 0) {
        total = 0;
        result = i+1;
      }
    }
    return result;
  }
};


class Solution1 {
public:
  int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
    int n = gas.size();
    int total_gas = 0, current_gas = 0;
    int start = 0;
    for (int i = 0; i < n; i++) {
      total_gas += gas[i] - cost[i];
      current_gas += gas[i] - cost[i];
      if (current_gas < 0) {
        start = i + 1;
        current_gas = 0;
      }
    }
    return total_gas >= 0 ? start : -1;
  }
};
