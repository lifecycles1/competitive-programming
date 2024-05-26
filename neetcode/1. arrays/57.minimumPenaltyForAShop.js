// 2483. Minimum Penalty for a Shop

// You are given the customer visit log of a shop represented by a 0-indexed string customers
// consisting only of characters 'N' and 'Y':
// if the ith character is 'Y', it means that customers come at the ith hour
// whereas 'N' indicates that no customers come at the ith hour.
// If the shop closes at the jth hour (0 <= j <= n), the penalty is calculated as follows:

// For every hour when the shop is open and no customers come, the penalty increases by 1.
// For every hour when the shop is closed and customers come, the penalty increases by 1.
// Return the earliest hour at which the shop must be closed to incur a minimum penalty.

// Note that if a shop closes at the jth hour, it means the shop is closed at the hour j.

// Example 1:
// Input: customers = "YYNY"
// Output: 2
// Explanation:
// - Closing the shop at the 0th hour incurs in 1+1+0+1 = 3 penalty.
// - Closing the shop at the 1st hour incurs in 0+1+0+1 = 2 penalty.
// - Closing the shop at the 2nd hour incurs in 0+0+0+1 = 1 penalty.
// - Closing the shop at the 3rd hour incurs in 0+0+1+1 = 2 penalty.
// - Closing the shop at the 4th hour incurs in 0+0+1+0 = 1 penalty.
// Closing the shop at 2nd or 4th hour gives a minimum penalty. Since 2 is earlier, the optimal closing time is 2.

// Example 2:
// Input: customers = "NNNNN"
// Output: 0
// Explanation: It is best to close the shop at the 0th hour as no customers arrive.

/**
 * @param {string} customers
 * @return {number}
 */
var bestClosingTime = function (customers) {
  var bestTime = 0,
    penaltyDiff = 0;

  for (var i = 0; i < customers.length; i++) {
    if (customers[i] == "Y") penaltyDiff--;
    else penaltyDiff++;

    if (penaltyDiff < 0) {
      penaltyDiff = 0;
      bestTime = i + 1;
    }
  }
  return bestTime;
};

// Time complexity: O(n)
// Space complexity: O(1)
var bestClosingTime = function (customers) {
  let max_score = 0,
    score = 0,
    best_hour = -1;
  for (let i = 0; i < customers.length; i++) {
    score += customers[i] === "Y" ? 1 : -1;
    if (score > max_score) {
      max_score = score;
      best_hour = 1;
    }
  }
  return best_hour + 1;
};
