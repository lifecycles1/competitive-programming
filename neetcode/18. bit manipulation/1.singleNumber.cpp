// Given a non-empty array of integers nums, every element appears twice except for one. Find that 
// single one.

// You must implement a solution with a linear runtime complexity and use only constant extra space.

// a XOR a returns 0, so returns 0 for all except the unique one
// Time: O(n)
// Space: O(1)

#include <vector>
using namespace std;

class Solution {
public:
  int singleNumber(vector<int>& nums) {
    int result = 0;

    for (int i = 0; i < nums.size(); i++) {
      result = result ^ nums[i];
    }

    return result;
  }
};