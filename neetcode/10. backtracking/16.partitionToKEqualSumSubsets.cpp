// Given an integer array nums and an integer k, return true if it is possible to divide 
// this array into k non-empty subsets whose sums are all equal.

#include <vector>
#include <numeric>
#include <algorithm>
#include <set>

class Solution {
public:
  bool canPartitionKSubsets(std::vector<int>& nums, int k) {
    if (accumulate(nums.begin(), nums.end(), 0) % k != 0) {
      return false;
    }
    sort(nums.begin(), nums.end(), std::greater<int>());
    int target = accumulate(nums.begin(), nums.end(), 0) / k;
    std::set<int> visited;
    return backtrack(0, 0, 0, k, target, visited, nums);
  }
private:
  bool backtrack(int idx, int count, int currSum, int k, int target, std::set<int>& visited, std::vector<int>& nums) {
    if (count == k) {
      return true;
    }
    if (target == currSum) {
      return backtrack(0, count+1, 0, k, target, visited, nums);
    }
    for (int i = idx; i < nums.size(); i++) {
      // skip duplicates if last same number was skipped
      if (i > 0 && visited.find(i-1) == visited.end() && nums[i] == nums[i-1]) {
        continue;
      }
      
      if (visited.find(i) != visited.end() || currSum + nums[i] > target) {
        continue;
      }

      visited.insert(i);

      if (backtrack(i+1, count, currSum+nums[i], k, target, visited, nums)) {
        return true;
      }

      visited.erase(i);
    }

    return false;
  }
};



