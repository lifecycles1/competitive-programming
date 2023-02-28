// Imagine a white rectangular grid of n rows and m columns divided into two parts by a 
// diagonal line running from the upper left to the lower right corner. 
// Now let's paint the grid in two colors according to the following rules:

// A cell is painted black if it has at least one point in common with the diagonal;
// Otherwise, a cell is painted white.
// Count the number of cells painted black.

#include <numeric>

class Solution {
public:
  int countBlackCells(int n, int m) {
    int whites = {};
    const auto scale = m / (double)n;

    for (int i = 1; i <= n; i++) {
      int temp = n - (int)(i*scale) - 1;
      if (temp >= 0) {
        whites += temp;
      }
    }
    return m * n - 2 * whites;
  }
};

class Solution {
public:
  int countBlackCells(int n, int m) {
    return n + m + std::gcd(n,m) - 2;
  }
};

class Solution {
public:
  int countBlackCells(int n, int m) {
    int k = n + m - 2;
    while (n != m) {
      if (n > m) {
        n -= m;
      } else {
        m -= n;
      }
    }
    return k + n;
  }
};