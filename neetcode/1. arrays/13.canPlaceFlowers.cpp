// You have a long flowerbed in which some of the plots are planted, and some are not. 
// However, flowers cannot be planted in adjacent plots.

// Given an integer array flowerbed containing 0's and 1's, where 0 means empty and 1 means not empty, 
// and an integer n, return if n new flowers can be planted in the flowerbed without violating 
// the no-adjacent-flowers rule.

# include <vector>
using namespace std;

class Solution {
public:
  bool canPlaceFlowers(vector<int>& flowerbed, int n) {
    // pre-check, if n is 0 .. return true
    if (n == 0) {
      return true;
    }

    // add a zero to the front and end of FB
    flowerbed.insert(flowerbed.begin(), 0);
    flowerbed.push_back(0);

    // iterate through vector (1, vector - 1) (for)
    // if prev, curr, and next are 0
    //    plant flower (1)
    //    decrement n
    for (int i = 1; i < flowerbed.size() - 1; i++) {
      if (flowerbed[i-1] == 0 && flowerbed[i] == 0 && flowerbed[i+1] == 0) {
        flowerbed[i] = 1;
        n--;
      }
      if (n == 0) {
        return true;
      }
    }

    // return false as else
    return false;
  }
};