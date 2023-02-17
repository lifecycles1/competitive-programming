// You are given an integer array nums. You want to maximize the number of points you 
// get by performing the following operation any number of times:

// Pick any nums[i] and delete it to earn nums[i] points. Afterwards, you must delete every 
// element equal to nums[i] - 1 and every element equal to nums[i] + 1.
// Return the maximum number of points you can earn by applying the above operation some number of times.

#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
  int deleteAndEarn(vector<int>& nums) {
    int upperLimit = 0;
    for (int i = 0; i < nums.size(); i++) {
      if (nums[i] > upperLimit) upperLimit = nums[i];
    }
    vector<int> sum(upperLimit+1, 0);
    for (int i = 0; i < nums.size(); i++) {
      sum[nums[i]] += nums[i];
    }
    vector<int> dp(upperLimit+1, 0);
    dp[1] = sum[1];
    for (int i = 2; i < upperLimit+1; i++) {
      dp[i] = max(dp[i-1], dp[i-2] + sum[i]);
    }
    return dp[upperLimit];
  }
};