// We define the weakness of number x as the number of positive integers smaller than x that have 
// more divisors than x.

// It follows that the weaker the number, the greater overall weakness it has. For the given 
// integer n, you need to answer two questions:

// what is the weakness of the weakest numbers in the range [1, n]?
// how many numbers in the range [1, n] have this weakness?
// Return the answer as an array of two elements, where the first element is the answer to the 
// first question, and the second element is the answer to the second question.

#include <vector>

class Solution {
public:
  std::vector<int> weakNumbers(int n) {
    std::vector<int> divisors(n + 1, 0);
    for (int i = 1; i <= n; ++i) {
      for (int j = i; j <= n; j += i) {
        ++divisors[j];
      }
    }
    std::vector<int> weakness(n + 1, 0);
    for (int i = 1; i <= n; ++i) {
      for (int j = 1; j < i; ++j) {
        if (divisors[j] > divisors[i]) {
          ++weakness[i];
        }
      }
    }
    int maxWeakness = 0;
    int maxWeaknessCount = 0;
    for (int i = 1; i <= n; ++i) {
      if (weakness[i] > maxWeakness) {
        maxWeakness = weakness[i];
        maxWeaknessCount = 1;
      } else if (weakness[i] == maxWeakness) {
        ++maxWeaknessCount;
      }
    }
    return {maxWeakness, maxWeaknessCount};
  }
};