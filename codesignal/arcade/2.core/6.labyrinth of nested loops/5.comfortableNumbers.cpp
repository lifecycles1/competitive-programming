// Let's say that number a feels comfortable with number b if a ≠ b and b lies in 
// the segment [a - s(a), a + s(a)], where s(x) is the sum of x's digits.

// How many pairs (a, b) are there, such that a < b, both a and b lie on the segment [l, r], 
// and each number feels comfortable with the other (so a feels comfortable with b and b feels 
// comfortable with a)?

class Solution {
public:
  int comfortableNumbers(int l, int r) {
    int count = 0;
    for (int a = l; a <= r; ++a) {
      for (int b = a + 1; b <= r; ++b) {
        if (b >= a - s(a) && b <= a + s(a) && a >= b - s(b) && a <= b + s(b)) {
          ++count;
        }
      }
    }
    return count;
  }
private:
  int s(int x) {
    int sum = 0;
    while (x) {
      sum += x % 10;
      x /= 10;
    }
    return sum;
  }
};