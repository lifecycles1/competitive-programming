// There are n oranges in the kitchen and you decided to eat some of these oranges every day as follows:

// Eat one orange.
// If the number of remaining oranges n is divisible by 2 then you can eat n / 2 oranges.
// If the number of remaining oranges n is divisible by 3 then you can eat 2 * (n / 3) oranges.
// You can only choose one of the actions per day.

// Given the integer n, return the minimum number of days to eat n oranges.

#include <unordered_map>
#include <functional>
using namespace std;

class Solution {
public:
  int minDays(int n) {
    unordered_map<int, int> dp = {{0, 0}, {1, 1}};

    function<int(int)> dfs = [&](int n) -> int {
      if (dp.count(n) > 0) {
        return dp[n];
      }

      int one = 1 + (n % 2) + dfs(n / 2);
      int two = 1 + (n % 3) + dfs(n / 3);
      dp[n] = min(one, two);
      return dp[n];
    };

    return dfs(n);
  }
};