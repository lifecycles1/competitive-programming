// Given an array of intervals intervals where intervals[i] = [starti, endi], return the minimum 
// number of intervals you need to remove to make the rest of the intervals non-overlapping.

// Remove interval w/ longer end point, since will always overlap more or = vs shorter one
// Time: O(n log n)
// Space: O(1)

#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
  int eraseOverlapIntervals(vector<vector<int>>& intervals) {
    int n = intervals.size();
    if (n == 1) {
      return 0;
    }
    sort(intervals.begin(), intervals.end(), [](const auto& a, const auto& b) {
      return a[0] < b[0];
    });

    int result = 0;

    int i = 0;
    while (i < n-1) {
      if (intervals[i][1] > intervals[i+1][0]) {
        if (intervals[i][1] < intervals[i+1][1]) {
          intervals[i+1] = intervals[i];
        }
        result++;
      }
      i++;
    }
    return result;
  }
};