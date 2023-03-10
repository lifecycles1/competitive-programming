// You are given a string s. We want to partition the string into as many parts as possible so that 
// each letter appears in at most one part.

// Note that the partition is done so that after concatenating all the parts in order, the resultant 
// string should be s.

// Return a list of integers representing the size of these parts.

//  Greedy: determine last occurrence of each char, then loop thru & get sizes
//  Time: O(n)
//  Space: O(1)

#include <vector>
#include <string>
using namespace std;

class Solution {
public:
  vector<int> partitionLabels(string s) {
    int n = s.size();
    // {char -> last index in s}
    vector<int> lastIndex(26);
    for (int i = 0; i < n; i++) {
      lastIndex[s[i] - 'a'] = i;
    }

    int size = 0;
    int end = 0;

    vector<int> result;

    for (int i = 0; i < n; i++) {
      size++;
      // constantly checking for further indices if possible
      end = max(end, lastIndex[s[i] - 'a']);
      if (i == end) {
        result.push_back(size);
        size = 0;
      }
    }
    return result;
  }
};