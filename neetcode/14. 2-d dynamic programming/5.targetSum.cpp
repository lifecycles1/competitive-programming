// You are given an integer array nums and an integer target.

// You want to build an expression out of nums by adding one of the symbols '+' and '-' before each 
// integer in nums and then concatenate all the integers.

// For example, if nums = [2, 1], you can add a '+' before 2 and a '-' before 1 and concatenate them 
// to build the expression "+2-1".
// Return the number of different expressions that you can build, which evaluates to target.

//solution 1
#include <vector>
#include <map>
// solution 2
#include <unordered_map>
#include <numeric>
using namespace std;

// 33% runtime
class Solution {
public:
  int findTargetSumWays(vector<int>& nums, int target) {
    return backtrack(nums, target, 0, 0);
  }
private:
  // {(index, total) -> # of ways}
  map<pair<int, int>, int> dp;

  int backtrack(vector<int>& nums, int target, int i, int total) {
    if (i == nums.size()) {
      return total == target ? 1 : 0;
    }
    if (dp.find({i, total}) != dp.end()) {
      return dp[{i, total}];
    }
    dp[{i, total}] = backtrack(nums, target, i+1, total+nums[i]) + backtrack(nums, target, i+1, total-nums[i]);

    return dp[{i, total}];
  }
};


// optimized solution 45% runtime
class Solution1 {
public:
  int findTargetSumWays(vector<int>& nums, int target) {
    int n = nums.size();
    int sum = accumulate(nums.begin(), nums.end(), 0);
    unordered_map<int, int> dp{{sum, 1}};
    for (int i = 0; i < n; i++) {
      unordered_map<int, int> next_dp;
      for (const auto& kv : dp) {
        int j = kv.first;
        int val = kv.second;
        next_dp[j + nums[i]] += val;
        next_dp[j - nums[i]] += val;
      }
      dp = next_dp;
    }
    return dp[sum + target];
  }
};

// further optimized 80% runtime
class Solution {
public:
  int findTargetSumWays(vector<int>& nums, int target) {
    target = abs(target);
    int n = nums.size();
    int sum = 0;
    for(int i = 0; i < n; i++) {
      sum += nums[i];
    }
    int M=(sum+target)/2;
    if (sum < target || (sum+target) % 2 != 0) {
      return 0;
    }
    return countSubsets(nums, n, M);
  }
private:
  int countSubsets(vector<int>& nums, int n, int M) {
    int t[n+1][M+1];

    for (int i = 0; i <= n; i++) {
      for (int j = 0; j <= M; j++) {
        if (i == 0) {
          t[i][j] = 0;
        }
        if (j == 0) {
          t[i][j] = 1;
        }
      }
    }
    //t[0][0] = 1;
    for(int i = 1; i <= n; i++) {
      for(int j = 0; j <= M; j++) {
        if(nums[i-1] <= j) {
          t[i][j] = t[i-1][j-nums[i-1]] + t[i-1][j];
        } else {
          t[i][j] = t[i-1][j];
        }
      }
    }
    return t[n][M];
  }
};

// almost 100% runtime
class Solution {
public:
  int findTargetSumWays(vector<int>& nums, int target) {
    // s1-s2 = target
    // s1+s2 = total
    // count of target total+target/2
    int n, total=0, sum=0;
    n = nums.size();
    for (int i=0; i < n; i++) {
      total+= nums[i];
    }
    if (abs(target) > total || (total+target) % 2 !=0) {
      return 0;
    }
    sum = (total+target) / 2;
    int t[n+1][sum+1];
    for (int i = 0; i < n+1; i++) {
      for (int j = 0; j < sum+1; j++) {
        t[0][j] = 0;
      }
    }
    t[0][0]=1;
    for (int i = 1; i < n+1; i++) {
      for (int j = 0; j < sum+1; j++) {
        if (nums[i-1] <= j) {
          t[i][j] = t[i-1][j-nums[i-1]] + t[i-1][j];
        } else {
          t[i][j]= t[i-1][j];
        }
      }
    }
    return t[n][sum];
  }
};