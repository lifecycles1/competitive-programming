// Given an array intervals where intervals[i] = [li, ri] represent the interval [li, ri), 
// remove all intervals that are covered by another interval in the list.

// The interval [a, b) is covered by the interval [c, d) if and only if c <= a and b <= d.

// Return the number of remaining intervals.

# include <vector>
# include <algorithm>
using namespace std;

// sort
class Solution {
public:
  int removeCoveredIntervals(vector<vector<int>>& A) {
    int res = 0, left = -1, right = -1;
    sort(A.begin(), A.end());
    for (auto& v: A) {
      if (v[0] > left && v[1] > right) {
        left = v[0];
        ++res;
      }
      right = max(right, v[1]);
    }
    return res;
  }
};