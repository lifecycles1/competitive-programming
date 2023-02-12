// Write an algorithm to determine if a number n is happy.

// A happy number is a number defined by the following process:

// Starting with any positive integer, replace the number by the sum of the squares of its digits.
// Repeat the process until the number equals 1 (where it will stay), or it loops endlessly in a 
// cycle which does not include 1.
// Those numbers for which this process ends in 1 are happy.
// Return true if n is a happy number, and false if not.

// Given num, replace by sum of squares of its digits
// Repeat until 1 or endless loop, determine if ends in 1
// Ex. n = 19 -> true, 1^2 + 9^2 = 82, 8^2 + 2^2 = 68 ... 1
// Detect cycle w/ slow/fast pointer technique
// If happy will eventually be 1, else pointers will meet
// Time: O(log n)
// Space: O(1)

#include <cmath>

class Solution {
public:
  bool isHappy(int n) {
    int slow = n;
    int fast = getNext(n);

    while (slow != fast && fast != 1) {
      slow = getNext(slow);
      fast = getNext(getNext(fast));
    }

    if (fast == 1) {
      return true;
    }

    return false;
  }
private:
  int getNext(int n) {
    int sum = 0;
    while (n > 0) {
      int digit = n % 10;
      n /= 10;
      sum += pow(digit, 2);
    }
    return sum;
  }
};