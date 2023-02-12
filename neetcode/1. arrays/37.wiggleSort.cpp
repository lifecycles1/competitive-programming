// Suppose we have an unsorted array called nums, we have to reorder it in-place such that 
// nums[0] <= nums[1] >= nums[2] <= nums[3].... and so on.

// So, if the input is like nums = [3,5,2,1,6,4], then the output will be [3,5,1,6,2,4], there may 
// be some other answers.

#include <vector>
using namespace std;

class Solution {
public:
  void wiggleSort(vector<int>& nums) {
    int n = nums.size();
    for (int i = 0; i < n-1; i++) {
      if ((i % 2 == 0) == (nums[i] > nums[i+1])) {
        swap(nums[i], nums[i+1]);
      }
    }
  }
};