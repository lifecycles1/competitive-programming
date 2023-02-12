// Given an array nums of n integers where nums[i] is in the range [1, n], return an array of 
// all the integers in the range [1, n] that do not appear in nums.

// Approach: 
// Traverse the entire array from start to end. Since the numbers are in a range [1, n] 
// we can use this simple trick.
// At every index mark the position arr[arr[i]] as negative.
// Repeat this for every index in the array.
// At the end, which ever places are positive, add them to our answer.

// Time complexity: O(n)
// Space complexity: O(1)

#include <vector>
using namespace std;

// faster solution
class Solution {
public:
  vector<int> findDisappearedNumbers(vector<int>& nums) {
    vector<int> res;
    for (int i = 0; i < nums.size(); i++) {
      int idx = abs(nums[i]) - 1;
      if (nums[idx] > 0) {
        nums[idx] *= -1;
      }
    }
    for (int i = 0; i < nums.size(); i++) {
      if (nums[i] > 0) {
        res.push_back(i + 1);
      }
    }
    return res;
  }
};

class Solution {
public:
  vector<int> findDisappearedNumbers(vector<int>& nums) {
    vector<int> ans;
    for (int x : nums) { /* Mark values as negative*/
      int currentVal = abs(x);
      nums[currentVal-1] = 0 - abs(nums[currentVal-1]);
    }
    for (int i = 1; i <= nums.size(); i++) {
      if (nums[i-1] > 0) {
        ans.push_back(i); /* Find unmarked values */
      }
    }
    return ans;
  }
};