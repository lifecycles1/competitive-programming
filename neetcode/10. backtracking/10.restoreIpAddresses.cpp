// A valid IP address consists of exactly four integers separated by single dots. 
// Each integer is between 0 and 255 (inclusive) and cannot have leading zeros.

// For example, "0.1.2.201" and "192.168.1.1" are valid IP addresses, but "0.011.255.245", 
// "192.168.1.312" and "192.168@1.1" are invalid IP addresses.
// Given a string s containing only digits, return all possible valid IP addresses that can be 
// formed by inserting dots into s. You are not allowed to reorder or remove any digits in s. 
// You may return the valid IP addresses in any order.

#include <vector>
#include <string>
using namespace std;

class Solution {
public:
  vector<string> restoreIpAddresses(string s) {
    vector<string> res;
    backtrack(s, 0, vector<int>(), res);
    return res;
  }
private:
  void backtrack(string s, int start, vector<int> path, vector<string>& res) {
    if (path.size() == 4) {
      if (start == s.length()) {
        string ip;
        for (int i = 0; i < 4; i++) {
          ip += to_string(path[i]);
          if (i != 3) ip += '.';
        }
        res.push_back(ip);
      }
      return;
    }
    for (int i = start; i < start + 3; i++) {
      if (i < s.size()) {
        if (i > start && s[start] == '0') {
          break;
        }
        if (stoi(s.substr(start, i - start + 1)) <= 255) {
          path.push_back(stoi(s.substr(start, i - start + 1)));
          backtrack(s, i + 1, path, res);
          path.pop_back();
        }
      }
    }
  }
};

class Solution {
public:
  vector<string> restoreIpAddresses(string s) {
    vector<string> res;
    string ip;
    dfs(s, 0, 0, ip, res);
    return res;
  }
    
  void dfs(string s, int start, int step, string ip, vector<string>& res) {
    if (start == s.size() && step == 4) {
      ip.erase(ip.end() - 1);
      res.push_back(ip);
      return;
    }
    if (s.size() - start > (4 - step) * 3) return;
    if (s.size() - start < (4 - step)) return;
    
    int num = 0;
    for (int i = start; i < start + 3; i++) {
      num = num * 10 + (s[i] - '0');
      if (num <= 255) {
        ip += s[i];
        dfs(s, i + 1, step + 1, ip + '.', res);
      }
      if (num == 0) break;
    }
  }
};