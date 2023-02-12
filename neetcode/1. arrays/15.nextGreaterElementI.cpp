// The next greater element of some element x in an array is the first greater element that is to 
// the right of x in the same array.

// You are given two distinct 0-indexed integer arrays nums1 and nums2, where nums1 is a subset of nums2.

// For each 0 <= i < nums1.length, find the index j such that nums1[i] == nums2[j] and determine the next 
// greater element of nums2[j] in nums2. If there is no next greater element, then the answer for this 
// query is -1.

// Return an array ans of length nums1.length such that ans[i] is the next greater element as described 
// above.

#include <vector>
#include <map>
#include <stack>
using namespace std;

// O(n+m) time
class Solution  {
public:
  vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
    map<int, int> nums1Idx; {
      int idx = 0;
      for (int n : nums1) {
        nums1Idx[n] = idx++;
      }
    }
    vector<int> res;
    for (int i = 0; i < nums1.size(); i++) {
      res.push_back(-1);
    }
    stack<int> stack;
    for (int i = 0; i < nums2.size(); i++) {
      int cur = nums2[i];

      // while stack has elements and cur is greater than the top of the stack
      while (stack.size() && cur > stack.top()) {
        int val = stack.top(); // take top val
        stack.pop();
        int idx = nums1Idx[val];
        res[idx] = cur;
      }
      if (nums1Idx.count(cur)) {
        stack.push(cur);
      }
    }
    return res;
  }
};