// You are given an array of non-overlapping intervals intervals where intervals[i] = [starti, endi] 
// represent the start and the end of the ith interval and intervals is sorted in ascending order 
// by starti. You are also given an interval newInterval = [start, end] that represents the start 
// and end of another interval.

// Insert newInterval into intervals such that intervals is still sorted in ascending order by starti 
// and intervals still does not have any overlapping intervals (merge overlapping intervals if necessary).

// Return intervals after the insertion.

// Ex. intervals = [[1,3],[6,9]], newInterval = [2,5] -> [[1,5],[6,9]]

// To merge: while intervals are still overlapping the new one, take the larger bounds
// Time: O(n)
// Space: O(n)

# include <vector>
using namespace std;

class Solution {
public:
  vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
    int i = 0;
    int n = intervals.size();
    vector<vector<int>> result;
    while (i < n && intervals[i][1] < newInterval[0]) {
      result.push_back(intervals[i]);
      i++;
    }
    while (i < n && intervals[i][0] <= newInterval[1]) {
      newInterval[0] = min(newInterval[0], intervals[i][0]);
      newInterval[1] = max(newInterval[1], intervals[i][1]);
      i++;
    }
    result.push_back(newInterval);
    while (i < n) {
      result.push_back(intervals[i]);
      i++;
    }
    return result;
  }
};