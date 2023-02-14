// Given a string s, rearrange the characters of s so that any two adjacent characters are not the same.

// Return any possible rearrangement of s or return "" if not possible.

# include < string >
# include < unordered_map >
# include < queue >
using namespace std;

class Solution {
public:
  string reorganizeString(string s) {
    unordered_map<char, int> m;
    for (char c : s) {
      m[c]++;
    }
    priority_queue<pair<int, char>> pq;
    for (auto it : m) {
      pq.push({it.second, it.first});
    }
    string res;
    while (!pq.empty()) {
      auto t1 = pq.top();
      pq.pop();
      if (res.empty() || res.back() != t1.second) {
        res.push_back(t1.second);
        if (--t1.first > 0) {
          pq.push(t1);
        }
      } else {
        if (pq.empty()) {
          return "";
        }
        auto t2 = pq.top();
        pq.pop();
        res.push_back(t2.second);
        if (--t2.first > 0) {
          pq.push(t2);
        }
        pq.push(t1);
      }
    }
    return res;
  }
};