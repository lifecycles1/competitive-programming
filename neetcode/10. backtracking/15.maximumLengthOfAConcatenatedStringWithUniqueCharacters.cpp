// You are given an array of strings arr. A string s is formed by the concatenation of a 
// subsequence of arr that has unique characters.

// Return the maximum possible length of s.

// A subsequence is an array that can be derived from another array by deleting some or no 
// elements without changing the order of the remaining elements.

#include <vector>
#include <string>
#include <set>
using namespace std;

class Solution {
public:
  int maxLength(vector<string>& arr) {
    set<char> charSet;
    return backtrack(0, charSet, arr);
  }
private:
  bool overlap(set<char>& charSet, string& s) {
    set<char> prev;
    for (char c : s) {
      if (charSet.find(c) != charSet.end() || prev.find(c) != prev.end()) {
        return true;
      }
      prev.insert(c);
    }
    return false;
  }

  int backtrack(int i, set<char>& charSet, vector<string>& arr) {
    if (i == arr.size()) {
      return charSet.size();
    }
    int res = 0;
    if (!overlap(charSet, arr[i])) {
      for (char c : arr[i]) {
        charSet.insert(c);
      }
      res = backtrack(i+1, charSet, arr);
      for (char c : arr[i]) {
        charSet.erase(c);
      }
    }
    return max(res, backtrack(i+1, charSet, arr));
  }
};