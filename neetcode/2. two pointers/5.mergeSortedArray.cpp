// You are given two integer arrays nums1 and nums2, sorted in non-decreasing order, 
// and two integers m and n, representing the number of elements in nums1 and nums2 respectively.

// Merge nums1 and nums2 into a single array sorted in non-decreasing order.

// The final sorted array should not be returned by the function, but instead be stored inside 
// the array nums1. To accommodate this, nums1 has a length of m + n, where the first m elements 
// denote the elements that should be merged, and the last n elements are set to 0 and should be ignored. 
// nums2 has a length of n.

#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
  void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    int j = 0;
    int i = 0;
    if (n == 0) {
      return;
    }
    if (m == 0) {
      for (int i = 0; i < n; i++) {
        nums1[i] = nums2[i];
      }
      return;
    }
    while (i < m) {
      if (nums1[i] > nums2[j]) {
        swap(nums1[i], nums2[j]);
        sort(nums2.begin(), nums2.end());
      }
      i++;
    }
    j = 0;
    while (i < m+n) {
      nums1[i] = nums2[j];
      i++;
      j++;
    }
  }
};

// a bit easier to read but a bit slower
class Solution {
public:
  void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    int i = m-1;
    int j = n-1;
    int tar = m+n-1;
    while (j >= 0) {
      nums1[tar--] = i >= 0 && nums1[i] > nums2[j] ? nums1[i--] : nums2[j--];
    }
  }
};