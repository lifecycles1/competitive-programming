// You are given an integer array nums. You are initially positioned at the array's first index, 
// and each element in the array represents your maximum jump length at that position.

// Return true if you can reach the last index, or false otherwise.

#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
  bool canJump(vector<int>& nums) {
    int n = nums.size();
    int reachable = 0;

    for (int i = 0; i < n; i++) {
      if (i > reachable) {
        return false;
      }
      reachable = max(reachable, i+nums[i]);
      if (reachable >= n-1) {
        break;
      }
    }
    return true;
  }
};