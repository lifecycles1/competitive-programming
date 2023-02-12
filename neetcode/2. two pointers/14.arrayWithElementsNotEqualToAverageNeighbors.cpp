// You are given a 0-indexed array nums of distinct integers. You want to rearrange the elements in 
// the array such that every element in the rearranged array is not equal to the average of its neighbors.

// More formally, the rearranged array should have the property such that for every i in the 
// range 1 <= i < nums.length - 1, (nums[i-1] + nums[i+1]) / 2 is not equal to nums[i].

// Return any rearrangement of nums that meets the requirements.

# include < vector > 
using namespace std;

class Solution {
public:
  vector<int> rearrangeArray(vector<int>& nums) {
    vector<int> ans;
    for (int i = 1; i < nums.size() - 1; i++) {
      int a = nums[i-1];
      int b = nums[i];
      int c = nums[i+1];
      if ( a > b && b > c || a < b && b < c) {
        swap(nums[i], nums[i+1]);
      }
    }
    return nums;
  }
};