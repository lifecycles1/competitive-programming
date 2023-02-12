// You are given a 0-indexed integer array nums, where nums[i] represents the score of the ith student. 
// You are also given an integer k.

// Pick the scores of any k students from the array so that the difference between the highest and the 
// lowest of the k scores is minimized.

// Return the minimum possible difference.

# include <vector>
# include <algorithm>
using namespace std;

// 45% runtime
class Solution {
public:
  int minimumDifference(vector<int>& nums, int k) {
    sort(nums.begin(), nums.end());
    int l = 0;
    int r = k-1;
    int res = INT_MAX;

    while (r < nums.size()) {
      res = min(res, nums[r] - nums[l]);
      l = l + 1;
      r = r + 1;
    }
    return res;
  }
};

// faster solution
class Solution {
public:
  int minimumDifference(vector<int>& nums, int k) {
    sort(nums.begin(), nums.end());
    int ans = INT_MAX;
    for (int i = k-1; i < nums.size(); i++) {
      ans = min(ans, nums[i]-nums[i-k+1]);
    }
    return ans;
  }
};