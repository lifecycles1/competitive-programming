// Find the number of ways to express n as sum of some (at least two) consecutive positive integers.

class Solution {
public:
  int isSumOfConsecutive2(int n) {
    int count = 0;
    for (int i = 1; i < n; i++) {
      int sum = 0;
      for (int j = i; j < n; j++) {
        sum += j;
        if (sum == n) {
          count++;
          break;
        }
        if (sum > n) break;
      }
    }
    return count;
  }
};