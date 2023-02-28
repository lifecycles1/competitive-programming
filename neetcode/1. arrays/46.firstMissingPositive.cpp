// Given an unsorted integer array nums, return the smallest missing positive integer.

// You must implement an algorithm that runs in O(n) time and uses constant extra space.

#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
  int firstMissingPositive(vector<int>& nums) {
    for (int i = 0; i < nums.size(); i++) {
      if (i+1 == nums[i]) {
        continue;
      }
      int x = nums[i];
      while (x >= 1 && x <= nums.size() && x!= nums[x-1]) {
        swap(x, nums[x-1]);
      }
    }
    for (int i = 0; i < nums.size(); i++) {
      if (i+1 != nums[i]) {
        return i+1;
      }
    }
    return nums.size() + 1;
  }
};


int main() {
  vector<int> nums = {-20, -100, 18, 25, 7, 1, -6, 2, 100, 75};
  cout << Solution().firstMissingPositive(nums) << endl;
  return 0;
}