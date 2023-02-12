// Given an array of integers nums and an integer k, return the total number of subarrays whose sum 
// equals to k.

// A subarray is a contiguous non-empty sequence of elements within an array.

# include < vector >
# include < unordered_map > 
using namespace std ;

class Solution {
public:
  int subarraySum(vector<int>& nums, int target) {
    int i = 0;
    int j = 0;
    int count = 0;
    int n = size(nums);
    int sum = 0;
    unordered_map <int, int> mp;
    while (j < n) {
      sum += nums[j];
      if (sum == target) {
        count++;
      }
      if (mp.find(sum-target) != mp.end()) {
        count += mp[sum-target];
      }
      mp[sum]++;
      j++;
    }
    return count;
  }
};