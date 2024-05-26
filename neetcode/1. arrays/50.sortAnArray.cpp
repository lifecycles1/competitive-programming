// Given an array of integers nums, sort the array in ascending order and return it.

// You must solve the problem without using any built-in functions in O(nlog(n)) time complexity 
// and with the smallest space complexity possible

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  vector<int> sortArray(vector<int>& nums) {
    mergeSort(nums, 0, nums.size() - 1);
    return nums;
  }
private:
  void merge(vector<int>& arr, int L, int M, int R) {
    vector<int> left(arr.begin() + L, arr.begin() + M + 1);
    vector<int> right(arr.begin() + M + 1, arr.begin() + R + 1);
    int i = L;
    int j = 0;
    int k = 0;
    while (j < left.size() && k < right.size()) {
      if (left[j] <= right[k]) {
        arr[i] = left[j];
        j++;
      } else {
        arr[i] = right[k];
        k++;
      }
      i++;
    }
    while (j < left.size()) {
      arr[i] = left[j];
      j++;
      i++;
    }
    while (k < right.size()) {
      arr[i] = right[k];
      k++;
      i++;
    }
  }

  void mergeSort(vector<int>& arr, int l, int r) {
    if (l < r) {
      int m = l + (r - l) / 2;
      mergeSort(arr, l, m);
      mergeSort(arr, m + 1, r);
      merge(arr, l, m, r);
    }
  }
};
