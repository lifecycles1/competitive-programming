// You are given a 0-indexed array of integers nums of length n. You are initially positioned at nums[0].

// Each element nums[i] represents the maximum length of a forward jump from index i. 
// In other words, if you are at nums[i], you can jump to any nums[i + j] where:

// 0 <= j <= nums[i] and
// i + j < n
// Return the minimum number of jumps to reach nums[n - 1]. The test cases are generated such that 
// you can reach nums[n - 1].

#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
  int jump(vector<int>& nums) {
    int n = nums.size();
    int result = 0;

    int i = 0;
    while (i < n-1) {
      if (i + nums[i] >= n-1) {
        result++;
        break;
      }
      int maxIndex = i+1;
      int maxValue = 0;
      for (int j = i+1; j < i+1+nums[i]; j++) {
        if (j + nums[j] > maxValue) {
          maxIndex = j;
          maxValue = j + nums[j];
        }
      }
      i = maxIndex;
      result++;
    }
    return result;
  }
};