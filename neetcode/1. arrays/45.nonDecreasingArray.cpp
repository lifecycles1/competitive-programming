// Given an array nums with n integers, your task is to check if it could become non-decreasing 
// by modifying at most one element.

// We define an array is non-decreasing if nums[i] <= nums[i + 1] holds for every i (0-based) 
// such that (0 <= i <= n - 2).

#include <vector>
using namespace std;

class Solution {
public:
  bool checkPossibility(vector<int>& nums) {
    int count = 0;
    for (int i = 1; i < nums.size(); i++) {
      if (nums[i-1] > nums[i]) {
        count++;
        if (i >= 2 && nums[i-2] > nums[i]) {
          nums[i] = nums[i-1];
        } else {
          nums[i-1] = nums[i];
        }
      }
    }
    return count <= 1;
  }
};