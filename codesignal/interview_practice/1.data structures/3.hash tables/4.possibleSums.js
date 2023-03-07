// You have a collection of coins, and you know the values of the coins and the quantity of
// each type of coin in it. You want to know how many distinct sums you can make from non-empty
// groupings of these coins.

class Solution {
  possibleSums(coins, quantity) {
    let sums = new Set();
    sums.add(0);
    for (let i = 0; i < coins.length; i++) {
      let newSums = new Set();
      for (let j = 0; j <= quantity[i]; j++) {
        sums.forEach((sum) => newSums.add(sum + j * coins[i]));
      }
      sums = newSums;
    }
    return sums.size - 1;
  }
}
