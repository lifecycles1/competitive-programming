// You have a collection of coins, and you know the values of the coins and the quantity of 
// each type of coin in it. You want to know how many distinct sums you can make from non-empty 
// groupings of these coins.

#include <iostream>
#include <vector>
#include <set>

class Solution {
public:
  int possibleSums(std::vector<int> coins, std::vector<int> quantity) {
    std::set<int> sums;
    sums.insert(0);
    for (int i = 0; i < coins.size(); ++i) {
      std::set<int> newSums;
      for (int j = 0; j <= quantity[i]; ++j) {
        for (auto sum : sums) {
          newSums.insert(sum + j * coins[i]);
        }
      }
      sums = newSums;
    }
    return sums.size() - 1;
  }
};