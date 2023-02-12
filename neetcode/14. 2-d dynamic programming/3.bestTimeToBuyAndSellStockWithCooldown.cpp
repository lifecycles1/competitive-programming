// You are given an array prices where prices[i] is the price of a given stock on the ith day.

// Find the maximum profit you can achieve. You may complete as many transactions as you like 
// (i.e., buy one and sell one share of the stock multiple times) with the following restrictions:

// After you sell your stock, you cannot buy stock on the next day (i.e., cooldown one day).
// Note: You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before 
// you buy again).

// Time: O(n)
// Space: O(1) -> optimized from O(n) since only need i - 1 prev state

# include <vector>
using namespace std;

class Solution {
public:
  int maxProfit(vector<int>& prices) {
    int n = prices.size();
    vector<int> s0(n, 0);
    vector<int> s1(n, 0);
    vector<int> s2(n, 0);

    s0[0] = 0;
    s1[0] = -prices[0];
    s2[0] = INT_MIN;
    for (int i = 1; i < n; i++) {
      s0[i] = max(s0[i-1], s2[i-1]);
      s1[i] = max(s1[i-1], s0[i-1] - prices[i]);
      s2[i] = s1[i-1] + prices[i];
    }
    return max(s0[n-1], s2[n-1]);
  }
};

class Solution1 {
public:
  int maxProfit(vector<int>& prices) {
    int sold = 0;
    int hold = INT_MIN;
    int rest = 0;

    for (int i = 0; i < prices.size(); i++) {
      int prevSold = sold;
      sold = hold + prices[i];
      hold = max(hold, rest - prices[i]);
      rest = max(rest, prevSold);
    }
    
    return max(sold, rest);
  }
};