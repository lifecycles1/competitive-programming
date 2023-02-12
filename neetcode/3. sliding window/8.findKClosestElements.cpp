// Given a sorted integer array arr, two integers k and x, return the k closest integers to x in the array. 
// The result should also be sorted in ascending order.

// An integer a is closer to x than an integer b if:

// |a - x| < |b - x|, or
// |a - x| == |b - x| and a < b

#include <vector>
using namespace std;

class Solution {
public:
  vector<int> findClosestElements(vector<int>& arr, int k, int x) {
    int l = 0;
    int r = arr.size() - k;

    while (l < r) {
      int m = (l + r) / 2; // m is the left index of the window
      if (x - arr[m] > arr[m + k] - x) {
        l = m+1;
      } else {
        r = m;
      }
    }
    return vector<int>(arr.begin() + l, arr.begin() + l + k);
  }
};