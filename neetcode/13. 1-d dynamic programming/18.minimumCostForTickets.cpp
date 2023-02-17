// You have planned some train traveling one year in advance. 
// The days of the year in which you will travel are given as an integer array days. 
// Each day is an integer from 1 to 365.

// Train tickets are sold in three different ways:

// a 1-day pass is sold for costs[0] dollars,
// a 7-day pass is sold for costs[1] dollars, and
// a 30-day pass is sold for costs[2] dollars.
// The passes allow that many days of consecutive travel.

// For example, if we get a 7-day pass on day 2, then we can travel for 7 days: 2, 3, 4, 5, 6, 7, and 8.
// Return the minimum number of dollars you need to travel every day in the given list of days.

#include <vector>
#include <unordered_map>
#include <algorithm>
#include <functional>

class Solution {
public:
  int mincostTickets(std::vector<int>& days, std::vector<int>& costs) {
    std::unordered_map<int, int> dp; // cache

    std::function<int(int)> dfs = [&](int i) -> int {
      if (i == days.size()) {
        return 0;
      }
      if (dp.find(i) != dp.end()) {
        return dp[i];
      }

      dp[i] = std::numeric_limits<int>::max(); // positive infinity
      for (const auto [d, c] : std::vector<std::pair<int, int>>{{1, costs[0]}, {7, costs[1]}, {30, costs[2]}}) {
        int j = i;
        while (j < days.size() && days[j] < days[i] + d) {
          j++; // next day we need to purchase a travel pass on
        }
        dp[i] = std::min(dp[i], c + dfs(j)); // c is the cost that took us to travel to j position
      }

      return dp[i];
    };

    return dfs(0);
  }
};


// actual dp solution without recursion
class Solution {
public:
  int mincostTickets(std::vector<int>& days, std::vector<int>& costs) {
    std::unordered_map<int, int> dp; // cache
    for (int i = days.size() - 1; i >= 0; i--) { // backwards loop (in reverse order) this way it matches the recursive solution
      dp[i] = std::numeric_limits<int>::max();
      for (const auto [d, c] : std::vector<std::pair<int, int>>{{1, costs[0]}, {7, costs[1]}, {30, costs[2]}}) {
        int j = i;
        while (j < days.size() && days[j] < days[i] + d) {
          j++;
        }
        dp[i] = std::min(dp[i], c + dp[j]);
      }
    }
    return dp[0];
  }
};