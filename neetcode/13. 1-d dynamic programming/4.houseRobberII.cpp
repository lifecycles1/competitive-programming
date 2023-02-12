// You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed. All houses at this place are 
// arranged in a circle. That means the first house is the neighbor of the last one. Meanwhile, 
// adjacent houses have a security system connected, and it will automatically contact the police 
// if two adjacent houses were broken into on the same night.

// Given an integer array nums representing the amount of money of each house, return the maximum amount 
// of money you can rob tonight without alerting the police

#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
  int rob(vector<int>& nums) {
    int n = nums.size();
    if (n == 1) {
      return nums[0];
    }
    int range1 = robber(nums, 0, n-2);
    int range2 = robber(nums, 1, n-1);

    return max(range1, range2);
  }
private:
  int robber(vector<int>& nums, int start, int end) {
    int prev = 0;
    int curr = 0;
    int next = 0;
    
    for (int i = start; i <= end; i++) {
      next = max(prev + nums[i], curr);
      prev = curr;
      curr = next;
    }

    return curr;
  }
};