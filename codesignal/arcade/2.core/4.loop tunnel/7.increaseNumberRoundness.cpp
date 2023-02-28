// Define an integer's roundness as the number of trailing zeroes in it.

// Given an integer n, check if it's possible to increase n's roundness by swapping some 
// pair of its digits.

class Solution {
public:
  bool increaseNumberRoundness(int n) {
    int l = 0;
    while (n) {
      if (l && n % 10 == 0)
        return true;
      l = n % 10;
      n /= 10;
    }
    return false;
  }
};