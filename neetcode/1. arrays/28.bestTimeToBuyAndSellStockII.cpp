// You are given an integer array prices where prices[i] is the price of a given stock on the ith day.

// On each day, you may decide to buy and/or sell the stock. You can only hold at most one share of 
// the stock at any time. However, you can buy it then immediately sell it on the same day.

// Find and return the maximum profit you can achieve.

// Approach: 
// If stock price is going up tomorrow just buy it today and sell it tomorrow.
// Time complexity : O(n)
// Space complexity: O(1)
// n is number of days.

#include <vector>
using namespace std;

class Solution {
public:
  int maxProfit(vector<int>& prices) {
    int ans = 0;

    // look into the next day and if you are making profit just buy it today
    for (int i = 1; i < prices.size(); i++) {
      if (prices[i] > prices[i-1]) {
        ans += (prices[i] - prices[i-1]);
      }
    }
    return ans;
  }
};