// Given an array of distinct integers nums and a target integer target, 
// return the number of possible combinations that add up to target.

// The test cases are generated so that the answer can fit in a 32-bit integer.

# include <unordered_map>
# include <vector>
# include <functional>
using namespace std;

class Solution {
public:
  int combinationSum4(vector<int>& nums, int target) {
    unordered_map<int, int> dp;
    dp[0] = 1;

    function<int(int)> search = [&](int target) -> int {
      if (dp.count(target) > 0) {
        return dp[target];
      }
      int comb_sum = 0;
      for (int num : nums) {
        if (target >= num) {
          comb_sum += search(target - num);
        }
      }
      dp[target] = comb_sum;
      return comb_sum;
    };

    return search(target);
  }
};

  
class Solution {
public:
  int combinationSum4(vector<int>& nums, int target) {
    vector<unsigned int> result(target + 1);
    result[0] = 1;
    for (int i = 1; i <= target; ++i) {
      for (int x : nums) {
        if (i >= x) result[i] += result[i - x];
      }
    }
    
    return result[target];
  }
};