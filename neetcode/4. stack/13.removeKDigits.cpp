// Given string num representing a non-negative integer num, and an integer k, return the 
// smallest possible integer after removing k digits from num.

#include <string>
#include <stack>
using namespace std;

class Solution {
public:
  string removeKdigits(string num, int k) {
    int n = num.size();

    stack<char> s;
    int count = k;

    for (int i = 0; i < n; i++) {
      while (!s.empty() && count > 0 && s.top() > num[i]) {
        s.pop();
        count--;
      }
      s.push(num[i]);
    }

    // in case the num was already in a non increasing order
    while (s.size() != n - k) {
      s.pop();
    }
    string res = "";
    while (!s.empty()) {
      res += s.top();
      s.pop();
    }
    reverse(res.begin(), res.end());
    // remove the zeroes from the left if they exist.
    while (res[0] == '0') {
      res.erase(0, 1);
    }
    return (res == "") ? "0" : res;
  }
};