// Given an array nums with n objects colored red, white, or blue, sort them in-place so that 
// objects of the same color are adjacent, with the colors in the order red, white, and blue.

// We will use the integers 0, 1, and 2 to represent the color red, white, and blue, respectively.

// You must solve this problem without using the library's sort function.

#include <vector>
using namespace std;

class Solution {
public:
  void sortColors(vector<int>& nums) {
    int p1 = 0;
    int p2 = nums.size() - 1;
    for (int i = p1; i <= p2; i++) {
      if (nums[i] == 0) {
        swap(nums[i], nums[p1]);
        p1++;
      }
      if (nums[i] == 2) {
        swap(nums[i], nums[p2]);
        p2--;
        i--;
      }
    }
  }
};