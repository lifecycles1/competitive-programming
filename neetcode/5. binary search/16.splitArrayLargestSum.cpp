// Given an integer array nums and an integer k, split nums into k non-empty subarrays such that the largest sum of 
// any subarray is minimized.

// Return the minimized largest sum of the split.

// A subarray is a contiguous part of the array.

#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
  int splitArray(std::vector<int>& nums, int m) {
    int left = 0;
    int right = 0;
    for (int i = 0; i < nums.size(); i++) {
      left = std::max(left, nums[i]);
      right += nums[i];
    }
    while (left < right) {
      int mid = left + (right - left) / 2;
      int sum = 0;
      int count = 1;
      for (int i = 0; i < nums.size(); i++) {
        if (sum + nums[i] > mid) {
          sum = nums[i];
          count++;
        } else {
          sum += nums[i];
        }
      }
      if (count > m) {
        left = mid + 1;
      } else {
        right = mid;
      }
    }
    return left;
  }
};