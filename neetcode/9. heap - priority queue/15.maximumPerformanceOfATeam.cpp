// You are given two integers n and k and two integer arrays speed and efficiency both of length n. 
// There are n engineers numbered from 1 to n. speed[i] and efficiency[i] represent the speed 
// and efficiency of the ith engineer respectively.

// Choose at most k different engineers out of the n engineers to form a team with the maximum performance.

// The performance of a team is the sum of their engineers' speeds multiplied by the minimum 
// efficiency among their engineers.

// Return the maximum performance of this team. Since the answer can be a huge number, 
// return it modulo 109 + 7.

#include <vector>
#include <queue> //priority_queue
#include <algorithm> //max
#include <utility> //pair
#include <functional> //greater
using namespace std;

class Solution {
public:
  int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
    vector<pair<int, int>> engineers;
    for (int i = 0; i < n; i++) {
      engineers.push_back({efficiency[i], speed[i]});
    }
    sort(engineers.begin(), engineers.end(), greater<pair<int, int>>());
    priority_queue<int, vector<int>, greater<int>> pq;
    long long sum = 0, res = 0;
    for (auto& engineer : engineers) {
      int e = engineer.first, s = engineer.second;
      pq.push(s);
      sum += s;
      if (pq.size() > k) {
        sum -= pq.top();
        pq.pop();
      }
      res = max(res, sum * e);
    }
    return res % (int)(1e9 + 7);
  }
};
