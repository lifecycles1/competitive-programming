// Given two version strings composed of several non-negative decimal fields separated by periods ("."), 
// both strings contain equal number of numeric fields. Return true if the first version is higher than 
// the second version and false otherwise.

// The syntax follows the regular semver ordering rules:

// 1.0.5 < 1.1.0 < 1.1.5 < 1.1.10 < 1.2.0 < 1.2.2
// < 1.2.10 < 1.10.2 < 2.0.0 < 10.0.0

// There are no leading zeros in any of the numeric fields, i.e. you do not have to handle inputs 
// like 100.020.003 (it would instead be given as 100.20.3).

#include <iostream>
#include <string>
#include <vector>
#include <sstream>

class Solution {
public:
  bool higherVersion(std::string ver1, std::string ver2) {
    std::vector<int> v1, v2;
    std::stringstream ss1(ver1);
    std::stringstream ss2(ver2);
    std::string temp;
    while (std::getline(ss1, temp, '.')) {
      v1.push_back(stoi(temp));
    }
    while (std::getline(ss2, temp, '.')) {
      v2.push_back(stoi(temp));
    }
    return v1 > v2;
  }
};