// Given a collection of numbers, nums, that might contain duplicates, 
// return all possible unique permutations in any order.

#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
  vector<vector<int>> permuteUnique(vector<int>& nums) {
    vector<vector<int>> res;
    vector<int> perm;
    vector<bool> used(nums.size(), false);
    sort(nums.begin(), nums.end());
    backtrack(nums, used, perm, res);
    return res;
  }
private:
  void backtrack(vector<int>& nums, vector<bool>& used, vector<int>& perm, vector<vector<int>>& res) {
    if (perm.size() == nums.size()) {
      res.push_back(perm);
      return;
    }
    for (int i = 0; i < nums.size(); i++) {
      if (used[i] || (i > 0 && nums[i] == nums[i-1] && !used[i-1])) {
        continue;
      }
      used[i] = true;
      perm.push_back(nums[i]);
      backtrack(nums, used, perm, res);
      perm.pop_back();
      used[i] = false;
    }
  }
};