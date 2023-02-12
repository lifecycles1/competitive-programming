// Given a string text, you want to use the characters of text to form as many instances 
// of the word "balloon" as possible.

// You can use each character in text at most once. Return the maximum number of instances that 
// can be formed.

# include <string>
# include <map>
using namespace std;

class Solution {
public:
  int maxNumberOfBalloons(string text) {
    map<char, int> countText;
    map<char, int> balloon;
    for (char c : text) {
      countText[c]++;
    }
    for (char c : string("balloon")) {
      balloon[c]++;
    }
    int res = text.length();
    for (const auto &[key, value]: balloon) {
      res = min(res, countText[key] / value);
    }
    return res;
  }
};