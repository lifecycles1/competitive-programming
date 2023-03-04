// Given an array of strings, return another array containing all of its longest strings.

#include <vector>
#include <string>

class Solution {
public:
  std::vector<std::string> allLongestStrings(std::vector<std::string> a) {
    std::vector<std::string> r;
    int max = 0;
    for (auto i : a) {
      if (i.size() > max) {
        max = i.size();
        r.clear();
        r.push_back(i);
      } else if (i.size() == max) {
        r.push_back(i);
      }
    }
    return r;
  }
};