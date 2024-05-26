
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  vector<int> mergeSort(vector<int> a) {
    if (a.size() == 1) return a;
    int mid = a.size() / 2;
    vector<int> left(a.begin(), a.begin() + mid);
    vector<int> right(a.begin() + mid, a.end());
    left = mergeSort(left);
    right = mergeSort(right);
    return merge(left, right);
  }
  vector<int> merge(vector<int> left, vector<int> right) {
    vector<int> result;
    while (left.size() > 0 || right.size() > 0) {
      if (left.size() > 0 && right.size() > 0) {
        if (left.front() <= right.front()) {
          result.push_back(left.front());
          left.erase(left.begin());
        } else {
          result.push_back(right.front());
          right.erase(right.begin());
        }
      } else if (left.size() > 0) {
        result.push_back(left.front());
        left.erase(left.begin());
      } else if (right.size() > 0) {
        result.push_back(right.front());
        right.erase(right.begin());
      }
    }
    return result;
  }
};

// quicker solution
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