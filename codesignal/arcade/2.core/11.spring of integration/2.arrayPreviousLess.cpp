// Given array of integers, for each position i, search among the previous positions for the last 
// (from the left) position that contains a smaller value. Store this value at position i in the answer. 
// If no such value can be found, store -1 instead.

// Example

// For items = [3, 5, 2, 4, 5], the output should be
// solution(items) = [-1, 3, -1, 2, 4].

#include <vector>

class Solution {
public:
  std::vector<int> arrayPreviousLess(std::vector<int> items) {
    std::vector<int> r;
    for(int i = 0; i < items.size(); ++i)
    {
        int s = -1;
        for(int j = 0; j < i; ++j)
            if(items[j] < items[i])
               s = items[j];
        r.push_back(s);
    }
    return r;
  }
};