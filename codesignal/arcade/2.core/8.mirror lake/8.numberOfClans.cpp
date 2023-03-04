// Let's call two integers A and B friends if each integer from the array divisors is either a 
// divisor of both A and B or neither A nor B. If two integers are friends, they are said to be 
// in the same clan. How many clans are the integers from 1 to k, inclusive, broken into?

#include <vector>
#include <set>

class Solution {
public:
  int numberOfClans(std::vector<int> divisors, int k) {
    std::set<int> r;
    for (int i = 1; i <= k; i++) {
      int v = 0;
      for (auto d : divisors)
        v = v << 1 | (i % d == 0);
      r.insert(v);
    }
    return r.size();
  }
};