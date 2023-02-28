// Determine if the given number is a power of some non-negative integer.

#include <cmath>
using namespace std;

class Solution {
public:
  bool isPower(int n) {
    if (n == 1) return true;
    for (int i = 2; i < n; i++) {
      int j = 2;
      while (pow(i, j) <= n) {
        if (pow(i, j) == n) return true;
        j++;
      }
    }
    return false;
  }
};