// You are given an array of integers nums and an integer target.

// Return the number of non-empty subsequences of nums such that the sum of the minimum and 
// maximum element on it is less or equal to target. Since the answer may be too large, return 
// it modulo 109 + 7

#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
  int mod = 1000000007;
  int numSubseq(vector<int>& nums, int target) {
    sort(nums.begin(), nums.end());
    int res = 0;
    int n = nums.size();
    int i = 0;
    int j = n-1;
    vector<int> pow2(n+1, 1);
    for (int i = 1; i <= n; i++) {
      pow2[i] = (2*pow2[i-1])%mod;
    }
    while (i <= j) {
      if (nums[j]+nums[i] <= target) {
        res = (res+pow2[j-i])%mod;
        i++;
      } else {
        j--;
      }
    }
    return res;
  }
};