// Given an array of n integers nums, a 132 pattern is a subsequence of three integers 
// nums[i], nums[j] and nums[k] such that i < j < k and nums[i] < nums[k] < nums[j].

// Return true if there is a 132 pattern in nums, otherwise, return false.

#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

class Solution {
public:
  bool find132pattern(vector<int>& nums) {
    // pair [num, minLeft], monotonic decreasing stack
    stack<pair<int, int>> stack_;
    int curMin = nums[0];

    for (const int& n : nums) {
      while (stack_.size() && n >= stack_.top().first) {
        stack_.pop();
      }
      if (stack_.size() && n > stack_.top().second) {
        return true;
      }
      stack_.emplace(n, curMin);
      curMin = min(curMin, n);
    }
    return false;
  }
};