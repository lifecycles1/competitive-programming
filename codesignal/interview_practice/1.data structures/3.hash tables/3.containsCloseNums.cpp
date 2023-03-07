// Given an array of integers nums and an integer k, determine whether there are two distinct 
// indices i and j in the array where nums[i] = nums[j] and the absolute difference between i and j 
// is less than or equal to k.

#include <iostream>
#include <vector>
#include <unordered_map>

class Solution {
public:
  bool containsCloseNums(std::vector<int> nums, int k) {
    std::unordered_map<int, int> map;
    for (int i = 0; i < nums.size(); i++) {
      if (map.find(nums[i]) != map.end() && i - map[nums[i]] <= k) {
        return true;
      }
      map[nums[i]] = i;
    }
    return false;
  }
};