// Given an integer array nums, return true if you can partition the array into two subsets such that 
// the sum of the elements in both subsets is equal or false otherwise.

// Ex. nums = [1,5,11,5] -> true, [1,5,5] & [11], both add to 11

// Maintain DP set, for each num, check if num in set + curr = target
// If not, add curr to every num in set we checked & iterate
// Time: O(n x sum(nums))
// Space: O(sum(nums))

#include <vector>
#include <unordered_set>
using namespace std;

// brute force solution
class Solution {
public:
  bool canPartition(vector<int>& nums) {
    int target = 0;
    for (int i = 0; i < nums.size(); i++) {
      target += nums[i];
    }
    if (target % 2 != 0) {
      return false;
    }
    target /= 2;

    unordered_set<int> dp;
    dp.insert(0);

    for (int i = 0; i < nums.size(); i++) {
      unordered_set<int> dpNext;
      for (auto it = dp.begin(); it != dp.end(); it++) {
        if (*it + nums[i] == target) {
          return true;
        }
        dpNext.insert(*it + nums[i]);
        dpNext.insert(*it);
      }
      dp = dpNext;
    }
    return false;
  }
};


// 1-row knapsack solution
class Solution1 {
public:
  bool canPartition(vector<int>& nums) {
    int target = 0;
    for (int i = 0; i < nums.size(); i++) {
      target += nums[i];
    }
    if (target % 2) {
      return false;
    }
    vector<int> row((target/2)+1, false);
    row[0] = true;

    for (int i = 1; i <= nums.size(); i++) {
      for (int j = target/2; j >= 0; j--) {
        if (j-nums[i-1] >= 0) {
          row[j]= row[j-nums[i-1]] || row[j];
        }
      }
    }
    return row[target/2];
  }
};