// You have k apple boxes full of apples. Each square box of size m contains m × m apples. 
// You just noticed two interesting properties about the boxes:

// The smallest box is size 1, the next one is size 2,..., all the way up to size k.
// Boxes that have an odd size contain only yellow apples. Boxes that have an even size 
// contain only red apples.
// Your task is to calculate the difference between the number of red apples and the number 
// of yellow apples.

#include <iostream>
using namespace std;

class Solution {
public:
  int solution(int k) {
    int red = 0, yellow = 0;
    for (int i = 1; i <= k; i++) {
      if (i % 2 == 0) {
        red += i * i;
      } else {
        yellow += i * i;
      }
    }
    return red - yellow;
  }
};

class Solution {
public:
  int solution(int k) {
    int red = 0, yellow = 0;
    while (k > 0) {
      if (k % 2) {
        yellow += k * k;
      } else {
        red += k * k;
      }
      k--;
    }
    return red - yellow;
  }
};