// Given a rectangular matrix of characters, add a border of asterisks(*) to it.

#include <iostream>
#include <vector>

class Solution {
public:
  std::vector<std::string> addBorder(std::vector<std::string> picture) {
    std::vector<std::string> result;
    std::string border(picture[0].size() + 2, '*');
    result.push_back(border);
    for (auto& s : picture) {
      result.push_back("*" + s + "*");
    }
    result.push_back(border);
    return result;
  }
};