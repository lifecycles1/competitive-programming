// You have n coins and you want to build a staircase with these coins. 
// The staircase consists of k rows where the ith row has exactly i coins. 
// The last row of the staircase may be incomplete.

// Given the integer n, return the number of complete rows of the staircase you will build.

class Solution {
public:
  int arrangeCoins(int n) {
    int l = 1;
    int r = n;
    int answer = 1;
    long long sum;
    long long m;

    // binary search the values
    while (l <= r) {
      m = l + (r-l) / 2;
      sum = m * (m+1) / 2;

      if (sum == n) {
        return (int)m;
      } else if (n < sum) {
        r = m - 1;
      } else {
        answer = (int)m;
        l = m+1;
      }
    }
    return answer;
  }
};