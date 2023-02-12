// You are climbing a staircase. It takes n steps to reach the top.

// Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?

// Climbing stairs, either 1 or 2 steps, distinct ways to reach top
// Ex. n = 2 -> 2 (1 + 1, 2), n = 3 -> 3 (1 + 1 + 1, 1 + 2, 2 + 1)
// this is basically a Fibonnaci sequence 
// Bottom up DP approach
// Time: O(n)
// Space: O(1)

class Solution {
public:
  int climbStairs(int n) {
    if (n == 1) {
      return 1;
    }
    if (n == 2) {
      return 2;
    }
    int first = 1;
    int second = 2;

    int result = 0;

    for (int i = 2; i < n; i++) {
      result = first + second;
      first = second;
      second = result;
    }
    
    return result;
  }
};