// Given an array of integers nums and an integer target, return indices of the two numbers such 
// that they add up to target.

// You may assume that each input would have exactly one solution, and you may not use the same element 
// twice.

// You can return the answer in any order.

// At each num, calculate complement, if exists in hash map then return
// Time: O(n)
// Space: O(n)

#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
  vector<int> twoSum(vector<int>& nums, int target) {
    unordered_map<int, int> indices;
    vector<int> result;

    for (int i = 0; i < nums.size(); i++) {
      int complement = target - nums[i];
      if (indices.find(complement) != indices.end()) {
        return {indices[complement], i};
      }
      indices[nums[i]] = i;
    }
    return {};
  }
};