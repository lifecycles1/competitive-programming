// Some file managers sort filenames taking into account case of the letters, 
// others compare strings as if all of the letters are of the same case. 
// That may lead to different ways of filename ordering.

// Call two filenames an unstable pair if their ordering depends on the case.

// To compare two filenames a and b, find the first position i at which a[i] ≠ b[i]. 
// If a[i] < b[i], then a < b. Otherwise a > b. If such position doesn't exist, the shorter string 
// goes first.

// Given two filenames, check whether they form an unstable pair.

#include <string>
#include <algorithm>
#include <cctype>
#include <iterator>

class Solution {
public:
  bool isUnstablePair(std::string filename1, std::string filename2) {
    return (filename1 < filename2) != (std::lexicographical_compare(filename1.begin(), filename1.end(), filename2.begin(), filename2.end(), [](char c1, char c2) { return std::tolower(c1) < std::tolower(c2); }));
  }
};

class Solution {
public:
  bool isUnstablePair(std::string filename1, std::string filename2) {
    std::string tn1, tn2;
    std::transform(begin(filename1), end(filename1), std::back_inserter(tn1), ::tolower);
    std::transform(begin(filename2), end(filename2), std::back_inserter(tn2), ::tolower);
  }
};