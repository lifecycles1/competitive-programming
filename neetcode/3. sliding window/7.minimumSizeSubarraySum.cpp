// Given an array of positive integers nums and a positive integer target, return the minimal length of a 
// subarray whose sum is greater than or equal to target. If there is no such subarray, return 0 instead.

# include <vector>
using namespace std;

class Solution {
public:
  int minSubArrayLen(int target, vector<int>& nums) {
    int l = 0;
    int total = 0;
    int res = INT_MAX;
    for (int r = 0; r < nums.size(); r++) {
      total += nums[r];
      while (total >= target) {
        res = min(r - l + 1, res);
        total -= nums[l];
        l++;
      }
    }
    return res == INT_MAX ? 0 : res;
  }
};