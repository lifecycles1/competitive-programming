// # Given an array a that contains only numbers in the range from 1 to a.length, 
// find the first duplicate number for which the second occurrence has the minimal index. 
// In other words, if there are more than 1 duplicated numbers, return the number for which 
// the second occurrence has a smaller index than the second occurrence of the other number does. 
// If there are no such elements, return -1.

#include <unordered_set>

class Solution {
public:
  int firstDuplicate(std::vector<int> a) {
    std::unordered_set<int> s;
    for (int i = 0; i < a.size(); i++) {
      if (s.find(a[i]) != s.end()) {
        return a[i];
      }
      s.insert(a[i]);
    }
    return -1;
  }
};

class Solution {
public:
  int firstDuplicate(std::vector<int> a) {
    for(int i=0; i < a.size(); i++){
      int t = abs(a[i]);
      if(a[t - 1] < 0)
        return t;
      a[t - 1] = - a[t - 1];
    }
    return -1;
  }
};