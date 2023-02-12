// The frequency of an element is the number of times it occurs in an array.

// You are given an integer array nums and an integer k. In one operation, you can choose an 
// index of nums and increment the element at that index by 1.

// Return the maximum possible frequency of an element after performing at most k operations.


//  Time: O(nlogn)
//   Space: O(1)

#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
  int maxFrequency(vector<int>& nums, long long k) {
    sort(nums.begin(), nums.end());
    int l = 0;
    int r = 0;
    int res = 0;
    long long total = 0;
    int n = nums.size();
    while (r < n) {
      total += nums[r];
      // invalid window
      while ((long)(r-l+1)*nums[r] > total+k) {
        total -= nums[l];
        l++;
      }
      res = max(res, r-l+1);
      r++;
    }
    return res;
  }
};