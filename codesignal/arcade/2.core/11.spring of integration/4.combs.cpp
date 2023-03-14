// Miss X has only two combs in her possession, both of which are old and miss a tooth or two. 
// She also has many purses of different length, in which she carries the combs. 
// The only way they fit is horizontally and without overlapping. Given teeth' positions on both combs, 
// find the minimum length of the purse she needs to take them with her.

// It is guaranteed that there is at least one tooth at each end of the comb.
// It is also guaranteed that the total length of two strings is smaller than 32.
// Note, that the combs can not be rotated/reversed.

// Example

// For comb1 = "*..*" and comb2 = "*.*", the output should be
// solution(comb1, comb2) = 5.

// A comb is represented as a string. If there is an asterisk ('*') in the ith position, there is a 
// tooth there. Otherwise there is a dot ('.'), which means there is a missing tooth on the comb.

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
  int combs(string comb1, string comb2) {
    string b1, b2;
    for (auto x : comb1) {
      if (x == '.') b1 += '0';
      else b1 += '1';
    }
    for (auto x : comb2) {
      if (x == '.') b2 += '0';
      else b2 += '1';
    }
    b1 = string(b2.length(), '0') + b1;
    vector<string> r;
    for (int i = 0; i < b1.length(); i++) {
      string x = b1.substr(0, i);
      for (int j = i, k = 0; j < b1.length() || k < b2.length(); j++, k++) {
        char a = j >= b1.length() ? '0' : b1[j];
        char b = k >= b2.length() ? '0' : b2[k];
        x += to_string(a - '0' + b - '0');
      }
      if (x.find('2') == string::npos) {
        r.push_back(x.substr(x.find_first_not_of('0')));
      }
    }
    sort(r.begin(), r.end(), [](const string& a, const string& b) {
      return a.length() < b.length();
    });
    return r[0].length();
  }
};