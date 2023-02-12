// Given an array arr, replace every element in that array with the greatest element among the 
// elements to its right, and replace the last element with -1.

// After doing so, return the array.

// O(n) time complexity, O(1) space complexity

#include <vector>
using namespace std;

class Solution {
public:
  vector<int> replaceElements(vector<int>& arr) {
    int n = arr.size();
    int maxSoFar = arr[n-1];
    arr[n-1] = -1;

    for (int i = n-2; i >= 0; i--) {
      int temp = maxSoFar;
      if (maxSoFar < arr[i]) {
        maxSoFar = arr[i];
      }
      arr[i] = temp;
    }
    return arr;
  }
};