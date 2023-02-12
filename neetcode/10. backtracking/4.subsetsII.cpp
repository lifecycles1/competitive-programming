// Given an integer array nums that may contain duplicates, return all possible 
// subsets
//  (the power set).

// The solution set must not contain duplicate subsets. Return the solution in any order.

// Ex. nums = [1,2,2] -> [[],[1],[1,2],[1,2,2],[2],[2,2]]
// Backtracking, generate all combos, push/pop + to explore new combos, skip duplicates
// Time: O(n x 2^n)
// Space: O(n)

#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
  vector<vector<int>> subsetsWithDup(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    vector<int> curr;
    vector<vector<int>> result;
    dfs(nums, 0, curr, result);
    return result;
  }
private:
  void dfs(vector<int>&nums, int start, vector<int>& curr, vector<vector<int>>& result) {
    result.push_back(curr);
    for (int i = start; i < nums.size(); i++) {
      if (i > start && nums[i] == nums[i-1]) {
        continue;
      }
      curr.push_back(nums[i]);
      dfs(nums, i+1, curr, result);
      curr.pop_back();
    }
  }
};