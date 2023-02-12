// Given an integer array nums, rotate the array to the right by k steps, where k is non-negative.

// 1.- To avoid problems with the size of the vector we use the remainder of a division.
// 2.- Reverse the entire vector.
// 3.- Reverse the parts you want to obtain the result.

// Time: O(1)
// Space: O(1)

#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
  void rotate(vector<int>& nums, int k) {
    k %= nums.size();
    reverse(nums.begin(), nums.end());
    reverse(nums.begin(), nums.begin() + k);
    reverse(nums.begin() + k, nums.end());
  }
};