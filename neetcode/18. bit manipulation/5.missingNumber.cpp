// Given an array nums containing n distinct numbers in the range [0, n], return the only number 
// in the range that is missing from the array.

// Given array in range [0, n], return missing
// Ex. nums = [3,0,1] -> 2, nums = [0,1] -> 2

// Use the fact that XOR is its own inverse
// Ex. [0,1,3,4]
// Missing = 4^(0^0)^(1^1)^(2^3)^(3^4)
//         = (4^4)^(0^0)^(1^1)^(3^3)^2
//         = 0^0^0^0^2 = 2

// Time: O(n)
// Space: O(1)

#include <vector>
using namespace std;

class Solution {
public:
  int missingNumber(vector<int>& nums) {
    int n = nums.size();
    int result = n;
    for (int i = 0; i < n; i++) {
      result ^= i ^ nums[i];
    }
    return result;
  }
};