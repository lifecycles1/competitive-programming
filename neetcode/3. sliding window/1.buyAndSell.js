// You are given an array prices where prices[i] is the price of a given stock on the ith day.

// You want to maximize your profit by choosing a single day to buy one stock and choosing a different day in
// the future to sell that stock.

// Return the maximum profit you can achieve from this transaction. If you cannot achieve any profit, return 0.

//////////////////////////////////////////
///////////  JavaScript solution 1 ///////
///////// One Pass ////////////

/**
 * @param {number[]} prices
 * @return {number}
 */
var maxProfit = function (prices) {
  let res = 0;
  let lowest = prices[0];
  for (const price of prices) {
    if (price < lowest) {
      lowest = price;
    }
    res = Math.max(res, price - lowest);
  }
  return res;
};

//////////////////////////////////////////
///////////  JavaScript solution 2 ///////
///////// Brute Force ////////////

/**
 * @param {number[]} prices
 * @return {number}
 */
var maxProfit = function (prices) {
  let left = 0;
  let right = 1;
  let max_profit = 0;

  while (right < prices.length) {
    if (prices[left] < prices[right]) {
      let profit = prices[right] - prices[left];
      max_profit = Math.max(max_profit, profit);
    } else {
      left = right;
    }
    right++;
  }
  return max_profit;
};

//////////////////////////////////////////
///////////  JavaScript solution 3 ///////
///////// Kadane's Algorithm ////////////

/**
 * @param {number[]} prices
 * @return {number}
 */
var maxProfit = function (prices) {
  let maxCur = 0;
  let maxSoFar = 0;

  for (let i = 1; i < prices.length; i++) {
    maxCur = Math.max(0, (maxCur += prices[i] - prices[i - 1]));
    maxSoFar = Math.max(maxCur, maxSoFar);
  }

  return maxSoFar;
};
