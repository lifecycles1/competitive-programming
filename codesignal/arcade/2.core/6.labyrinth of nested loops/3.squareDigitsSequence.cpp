// Consider a sequence of numbers a0, a1, ..., an, in which an element is equal to the sum of 
// squared digits of the previous element. The sequence ends once an element that has already 
// been in the sequence appears again.

// Given the first element a0, find the length of the sequence.

#include <set>

class Solution {
public:
  int squareDigitsSequence(int a0) {
    std::set<int> s;
    s.insert(a0);
    for(int n = 2; ;++n) {
      int y = a0;
      for(a0 = 0; y; y /= 10) {
        a0 += (y % 10) * (y % 10);
      }
      if (s.count(a0)) {
        return n;
      }
      s.insert(a0);
    }
  }
};