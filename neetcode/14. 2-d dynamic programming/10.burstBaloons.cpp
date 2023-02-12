// You are given n balloons, indexed from 0 to n - 1. Each balloon is painted with a number on it 
// represented by an array nums. You are asked to burst all the balloons.

// If you burst the ith balloon, you will get nums[i - 1] * nums[i] * nums[i + 1] coins. 
// If i - 1 or i + 1 goes out of bounds of the array, then treat it as if there is a balloon with 
// a 1 painted on it.

// Return the maximum coins you can collect by bursting the balloons wisely.

#include <vector>
#include <algorithm>
using namespace std;

// 40% runtime
class Solution {
public:
  int maxCoins(vector<int>& nums) {
    // add 1 before & after nums
    nums.insert(nums.begin(), 1);
    nums.insert(nums.end(), 1);
    int n = nums.size();

    // cache results of dp
    vector<vector<int>> memo(n, vector<int>(n, 0));

    // 1 & n - 2 since we can't burst our fake balloons
    return dp(nums, memo, 1, n-2); 
  }
private:
  int dp(vector<int>&nums, vector<vector<int>>& memo, int left, int right) {
    // base case interval is empty, yields 0 coins
    if (right - left < 0) {
      return 0;
    }

    // we've already seen this, return from cache
    if (memo[left][right] > 0) {
      return memo[left][right];
    }

    // find the last burst in nums[left]...nums[right]
    int result = 0;
    for (int i = left; i <= right; i++) {
      // nums[i] is the last burst
      int curr = nums[left-1] * nums[i] * nums[right+1];
      // nums[i] is fixed, recursively call left & right sides
      int remaining = dp(nums, memo, left, i-1) + dp(nums, memo, i+1, right);
      result = max(result, curr + remaining);
    }

    // add to cache
    memo[left][right] = result;
    return result;
  }
};

// 60% runtime
class Solution1 {
public:
  int maxCoins(vector<int> &A) {
    vector<int> nums;
    nums.push_back(1);
    for (int i = 0; i < A.size(); i++) {
      nums.push_back(A[i]);
    }
    nums.push_back(1);
    int n = nums.size();
    vector<vector<int>> dp(n, vector<int>(n, 0));
    
    for (int i = n - 2; i >= 0; i--) {
      for (int j = i + 2; j < n; j++) {
        for (int k = i + 1; k < j; k++) {
          dp[i][j] = max(dp[i][j], nums[i] * nums[k] * nums[j] + dp[i][k] + dp[k][j]);
        }
      }
    }
    
    return dp[0][n-1];
  }
};
