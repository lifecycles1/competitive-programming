// You are given an array of strings nums and an integer k. Each string in nums represents an 
// integer without leading zeros.

// Return the string that represents the kth largest integer in nums.

// Note: Duplicate numbers should be counted distinctly. For example, if nums is 
// ["1","2","2"], "2" is the first largest integer, "2" is the second-largest integer, 
// and "1" is the third-largest integer.

#include <vector>
#include <string>
#include <queue>
using namespace std;

class Solution {
private:
  static bool st(string &a, string &b) {
    if (a.size() == b.size()) {
      return a < b;
    }
    return a.size() < b.size();
  }
public:
  string kthLargestNumber(vector<string>& nums, int k) {
    sort(nums.begin(), nums.end(), st);
    return nums[nums.size() - k];
  }
};