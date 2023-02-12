// Given a positive integer num, return true if num is a perfect square or false otherwise.

// A perfect square is an integer that is the square of an integer. In other words, it is the product of some integer with itself.

// You must not use any built-in library function, such as sqrt.

// Approach: Binary search the number such that divind num by that number gives the number itself

// Time Complexity: log(n)
// Space Complexity: O(1)


class Solution {
public:
  bool isPerfectSquare(int num) {
    if (num == 1) {
      return true;
    }
    int l = 0;
    int r = num;
    while (l < r) {
      int m = l + (r-l) / 2;
      float x = (float)num / (float)m;
      if (x==m) {
        return true;
      } else if (x < m) {
        r = m;
      } else {
        l = m + 1;
      }
    }
    return false;
  }
};