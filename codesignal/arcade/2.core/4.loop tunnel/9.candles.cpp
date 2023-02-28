// When a candle finishes burning it leaves a leftover. 
// makeNew leftovers can be combined to make a new candle, which, when burning down, 
// will in turn leave another leftover.

// You have candlesNumber candles in your possession. What's the total number of candles you can burn, 
// assuming that you create new candles as soon as you have enough leftovers?

class Solution {
public:
  int candles(int candlesNumber, int makeNew) {
    int total = candlesNumber;
    int leftovers = candlesNumber;
    while (leftovers >= makeNew) {
      int newCandles = leftovers / makeNew;
      total += newCandles;
      leftovers = leftovers % makeNew + newCandles;
    }
    return total;
  }
};