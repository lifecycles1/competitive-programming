// Given an array of distinct integers candidates and a target integer target, return a list of all 
// unique combinations of candidates where the chosen numbers sum to target. You may return the 
// combinations in any order.

// The same number may be chosen from candidates an unlimited number of times. Two combinations are 
// unique if the frequency of at least one of the chosen numbers is different.

// The test cases are generated such that the number of unique combinations that sum up to target is less 
// than 150 combinations for the given input.

// Ex. candidates = [2,3,6,7] target = 7 -> [[2,2,3],[7]]
// Backtracking, generate all combo sums, push/pop + index checking to explore new combos
// Time: O(n^target)
// Space: O(target)

# include <vector>
# include <algorithm>
using namespace std;

class Solution {
public:
  vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    sort(candidates.begin(), candidates.end());
    vector<int> curr;
    vector<vector<int>> result;
    dfs(candidates, target, 0, 0, curr, result);
    return result;
  }
private:
  void dfs(vector<int>& candidates, int target, int sum, int start, vector<int>& curr, vector<vector<int>>& result) {
    if (sum > target) {
      return;
    }
    if (sum == target) {
      result.push_back(curr);
      return;
    }
    for (int i = start; i < candidates.size(); i++) {
      curr.push_back(candidates[i]);
      dfs(candidates, target, sum + candidates[i], i, curr, result);
      curr.pop_back();
    }
  }
};