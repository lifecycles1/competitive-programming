// A string s is called happy if it satisfies the following conditions:

// s only contains the letters 'a', 'b', and 'c'.
// s does not contain any of "aaa", "bbb", or "ccc" as a substring.
// s contains at most a occurrences of the letter 'a'.
// s contains at most b occurrences of the letter 'b'.
// s contains at most c occurrences of the letter 'c'.
// Given three integers a, b, and c, return the longest possible happy string. 
// If there are multiple longest happy strings, return any of them. 
// If there is no such string, return the empty string "".

// A substring is a contiguous sequence of characters within a string.

#include <string>
#include <queue>
#include <utility>
using namespace std;

class Solution {
public:
  string longestDiverseString(int a, int b, int c) {
    // max heap
    // (count, char)
    priority_queue<pair<int, char>> pq;
    if (a > 0) pq.push({ a, 'a' });
    if (b > 0) pq.push({ b, 'b' });
    if (c > 0) pq.push({ c, 'c' });

    string res = "";
    while (!pq.empty()) {
      auto p = pq.top();
      pq.pop();
      int count = p.first;
      char ch = p.second;

      if (res.size() >= 2 && res[res.size() - 1] == ch && res[res.size() - 2] == ch) {
        if (pq.empty()) break;
        auto p2 = pq.top();
        pq.pop();
        int count2 = p2.first;
        char ch2 = p2.second;
        res += ch2;
        if (--count2 > 0) pq.push({ count2, ch2 });
        pq.push({ count, ch });
      }
      else {
        res += ch;
        if (--count > 0) pq.push({ count, ch });
      }
    }

    return res;
  }
};