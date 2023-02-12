// Given a binary string s and an integer k, return true if every binary code of length k is a 
// substring of s. Otherwise, return false.

#include <string>
#include <set>
#include <unordered_set>
using namespace std;

// slower
class Solution {
public:
  bool hasAllCodes(string s, int k) {
    set<string> all_substrings;
    int total = 1 << k; // this is equal to 2 power k (2^k)

    // get all the substring of len k and store it in a set
    for (int i = 0; i+k <= s.length(); i++) {
      all_substrings.insert(s.substr(i, k));
      // size of set equals 2 power k
      if (all_substrings.size() == total) {
        return true;
      }
    }
    return false;
  }
};

// 80% runtime
class Solution {
public:
  bool hasAllCodes(string s, int k) {
    if (k > s.size()) {
      return false;
    }
    unordered_set<string> my_set;
    for (int i = 0; i <= s.size()-k; i++) {
      my_set.insert(s.substr(i, k));
    }
    return my_set.size() == pow(2, k);
  }
};