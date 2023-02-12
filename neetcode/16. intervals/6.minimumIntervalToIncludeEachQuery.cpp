// You are given a 2D integer array intervals, where intervals[i] = [lefti, righti] describes the ith 
// interval starting at lefti and ending at righti (inclusive). The size of an interval is defined as 
// the number of integers it contains, or more formally righti - lefti + 1.

// You are also given an integer array queries. The answer to the jth query is the size of the smallest 
// interval i such that lefti <= queries[j] <= righti. If no such interval exists, the answer is -1.

// Return an array containing the answers to the queries.

// Input: intervals = [[1,4],[2,4],[3,6],[4,4]], queries = [2,3,4,5]
// Output: [3,3,1,4]
// Explanation: The queries are processed as follows:
// - Query = 2: The interval [2,4] is the smallest interval containing 2. The answer is 4 - 2 + 1 = 3.
// - Query = 3: The interval [2,4] is the smallest interval containing 3. The answer is 4 - 2 + 1 = 3.
// - Query = 4: The interval [4,4] is the smallest interval containing 4. The answer is 4 - 4 + 1 = 1.
// - Query = 5: The interval [3,6] is the smallest interval containing 5. The answer is 6 - 3 + 1 = 4.

// Min heap & sort by size of intervals, top will be min size, 
// Time: O(n log n + q log q) -> n = number of intervals, q = number of queries
// Space: O(n + q)

#include <vector>
#include <queue>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
public:
  vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {
    vector<int> sortedQueries = queries;

    // [size of interval, end of interval]
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    // {query -> size of interval}
    unordered_map<int, int> m;

    // also need only valid intervals so sort by start time & sort queries
    sort(intervals.begin(), intervals.end());
    sort(sortedQueries.begin(), sortedQueries.end());

    vector<int> result;

    int i = 0;
    for (int j = 0; j < sortedQueries.size(); j++) {
      int query = sortedQueries[j];

      while (i < intervals.size() && intervals[i][0] <= query) {
        int left = intervals[i][0];
        int right = intervals[i][1];
        pq.push({right - left + 1, right});
        i++;
      }

      while (!pq.empty() && pq.top().second < query) {
        pq.pop();
      }

      if (!pq.empty()) {
        m[query] = pq.top().first;
      } else {
        m[query] = -1;
      }
    }
    for (int j = 0; j < queries.size(); j++) {
      result.push_back(m[queries[j]]);
    }
    return result;
  }
};