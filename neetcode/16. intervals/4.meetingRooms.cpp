// Given an array of meeting time intervals consisting of start and end times 
// [[s1,e1],[s2,e2],...] (si < ei), determine if a person could attend all meetings.

// Ex. intervals = [[0,30],[5,10],[15,20]] -> false
// Sort by start time, check adj meetings, if overlap return false
// Time: O(n log n)
// Space: O(1)

#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
  bool canAttendMeetings(vector<vector<int>>& intervals) {
    if (intervals.empty()) {
      return true;
    }
    sort(intervals.begin(), intervals.end());
    for (int i = 0; i < intervals.size(); i++) {
      if (intervals[i][1] > intervals[i+1][0]) {
        return false;
      }
    }
    return true;
  }
};