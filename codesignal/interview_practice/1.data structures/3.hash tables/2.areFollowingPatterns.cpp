// Given an array strings, determine whether it follows the sequence given in the patterns array. 
// In other words, there should be no i and j for which strings[i] = strings[j] 
// and patterns[i] ≠ patterns[j] or for which strings[i] ≠ strings[j] and patterns[i] = patterns[j].

// Example

// For strings = ["cat", "dog", "dog"] and patterns = ["a", "b", "b"], the output should be
// solution(strings, patterns) = true;

#include <iostream>
#include <vector>
#include <string>
#include <map>
using namespace std;

class Solution {
public:
  bool solution(vector<string> strings, vector<string> patterns) {
    map<string,string> sToP, pToS;
    int n = strings.size();
    for (int i = 0; i < n; ++i) {
      auto& s = strings[i];
      auto& p = patterns[i];
      if (sToP.count(s) > 0 && sToP[s] != p)
        return false;
      if (pToS.count(p) > 0 && pToS[p] != s)
        return false;
      sToP[s] = p;
      pToS[p] = s;
    }
    return true;
  }
};