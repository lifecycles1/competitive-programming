// N candles are placed in a row, some of them are initially lit. 
// For each candle from the 1st to the Nth the following algorithm is applied: 
// if the observed candle is lit then states of this candle and all candles before it are 
// changed to the opposite. Which candles will remain lit after applying the algorithm to all 
// candles in the order they are placed in the line?

#include <iostream>
#include <vector>

class Solution {
public:
  std::vector<bool> switchLights(std::vector<bool> a) {
    for (int i = 0; i < a.size(); ++i) {
      if (a[i]) {
        for (int j = 0; j <= i; ++j) {
          a[j] = !a[j];
        }
      }
    }
    return a;
  }
};