// A company is planning to interview 2n people. Given the array costs where 
// costs[i] = [aCosti, bCosti], the cost of flying the ith person to city a is aCosti, 
// and the cost of flying the ith person to city b is bCosti.

// Return the minimum cost to fly every person to a city such that exactly n people 
// arrive in each city.

# include <vector>
# include <algorithm>
using namespace std;

class Solution {
public:
  int twoCitySchedCost(vector<vector<int>>& costs) {
    sort(begin(costs), end(costs), [](auto& a, auto& b) {
      return a[0] - a[1] < b[0] - b[1];
    });
    int res = 0;
    for (int i = 0; i < costs.size() / 2; ++i)
      res += costs[i][0] + costs[i + costs.size() / 2][1];
    return res;
  }
};