// Given an integer array nums, return the number of longest increasing subsequences.

// Notice that the sequence has to be strictly increasing.

#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
  int findNumberOfLIS(vector<int>& nums) {
    int l = nums.size();
    vector<int> dp(l, 1);
    vector<int> count(l, 1);

    int maxLen = 0;
    int ans = 0;

    for (int i = 0; i < l; i++) {
      for (int j = 0; j < i; j++) {
        if (nums[i] > nums[j]) {
          if (dp[j] + 1 > dp[i]) {
            dp[i] = dp[j] + 1;
            count[i] = count[j];
          } else if (dp[j] + 1 == dp[i]) {
            count[i] += count[j];
          }
        }
      }
      if (dp[i] > maxLen) {
        maxLen = dp[i];
        ans = count[i];
      } else if (dp[i] == maxLen) {
        ans += count[i];
      }
    }
    return ans;
  }
};