// Write a function to find the longest common prefix string amongst an array of strings.

// If there is no common prefix, return an empty string "".

// Input: strs = ["flower","flow","flight"]
// Output: "fl"

#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
  string longestCommonPrefix(vector<string>& strs) {
    string result = strs[0];
    int charIndex = 0;

    // finding minimum string length - that could be max common prefix
    long maxCharIndex = strs[0].length();
    for (int i = 1; i < strs.size(); i++) {
      if (strs[i].length() < maxCharIndex) {
        maxCharIndex = strs[i].length();
      }
    }
    while (charIndex < maxCharIndex) {
      char prevChar = strs[0][charIndex];
      for (int i = 1; i < strs.size(); i++) {
        if (prevChar == strs[i][charIndex]) {
          continue;
        }
        return result.substr(0, charIndex);
      }
      charIndex++;
      result += prevChar;
    }
    return result.substr(0, charIndex);
  }
};


// a bit faster solution only checking first and last string after sorting all strings lexicographically
class Solution {
public:
  string longestCommonPrefix(vector<string>& strs) {
    if (strs.empty()) {
      return "";
    }
    sort(strs.begin(), strs.end());
    string first = strs[0];
    string last = strs[strs.size() - 1];
    int c = 0;
    while (c < first.length()) {
      if (first[c] == last[c]) {
        c++;
      } else {
        break;
      }
    }
    return c == 0 ? "" : first.substr(0, c);
  }
};