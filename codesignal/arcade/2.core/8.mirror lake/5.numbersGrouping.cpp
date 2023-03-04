// You are given an array of integers that you want distribute between several groups. 
// The first group should contain numbers from 1 to pow(10, 4), the second should contain those 
// from 10**4 + 1 to 2 * 10**4, ..., the 100th one should contain numbers from 99 * 10**4 + 1 to 10**6 
// and so on.

// All the numbers will then be written down in groups to the text file in such a way that:

// the groups go one after another;
// each non-empty group has a header which occupies one line;
// each number in a group occupies one line.
// Calculate how many lines the resulting text file will have.

#include <set>
#include <vector>

class Solution {
public:
  int numbersGrouping(std::vector<int> a) {
    std::set<int> r;
    for (auto n : a)
      r.insert((n - 1) / 10000);
    return r.size() + a.size();
  }
};