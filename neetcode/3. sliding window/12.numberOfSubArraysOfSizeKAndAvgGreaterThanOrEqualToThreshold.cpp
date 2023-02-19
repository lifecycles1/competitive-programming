// Given an array of integers arr and two integers k and threshold, 
// return the number of sub-arrays of size k and average greater than or equal to threshold.

#include <vector>
using namespace std;

class Solution {
public:
  int numOfSubarrays(vector<int>& arr, int k, int threshold) {
    int l = 0;
    int total = 0;
    int res = 0;
    for (int r = 0; r < arr.size(); r++) {
      total += arr[r];
      if (r - l + 1 == k) {
        if (total / k >= threshold) {
          res++;
        }
        total -= arr[l];
        l++;
      }
    }
    return res;
  }
};

// faster solution
class Solution {
public:
  int numOfSubarrays(vector<int> &arr, int k, int threshold) {
    int window_sum = 0;
    int count = 0;

    // step 1 : forming window sum for first window [starting at index (0) and ending at index (k - 1)]
    for(int i = 0 ; i < k ; ++i)
      window_sum += arr[i];
    
    // step 2 : loop through arr and find each window's average
    for(int i = 0 ; i < arr.size() - k + 1 ; ++i) {
      if(i != 0) {
        window_sum -= arr[i - 1];    // removing first element from prev window
        window_sum += arr[i + k - 1];// adding last + 1 elemnt in prev window
        // new window is ready
      }
        
      int window_average = window_sum / k;
        
      if(window_average >= threshold)
        count++;
    }

    return count;
  }
};