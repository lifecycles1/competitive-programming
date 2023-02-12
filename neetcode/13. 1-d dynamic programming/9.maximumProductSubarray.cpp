// Given an integer array nums, find a subarray that has the largest product, and return the product.

// The test cases are generated so that the answer will fit in a 32-bit integer.

#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
  int maxProduct(vector<int>& nums) {
    int res = nums[0];
    int curMin = 1, curMax = 1;

    for (int i = 0; i < nums.size(); i++) {
      int n = nums[i];
      int tmp = curMax * n;
      curMax = max(max(n*curMax, n*curMin), n);
      curMin = min(min(tmp, n*curMin), n);
      res = max(res, curMax);
    }
    return res;
  }
};