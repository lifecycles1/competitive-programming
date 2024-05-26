// Some people are standing in a row in a park. There are trees between them which cannot be moved. 
// Your task is to rearrange the people by their heights in a non-descending order without 
// moving the trees. People can be very tall!

// Example

// For a = [-1, 150, 190, 170, -1, -1, 160, 180], the output should be
// solution(a) = [-1, 150, 160, 170, -1, -1, 180, 190].

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
  vector<int> sortByHeight(vector<int> a) {
    vector<int> b;
    for (int i = 0; i < a.size(); i++) {
      if (a[i] != -1) {
        b.push_back(a[i]);
      }
    }
    sort(b.begin(), b.end());
    for (int i = 0, j = 0; i < a.size(); i++) {
      if (a[i] != -1) {
        a[i] = b[j++];
      }
    }
    return a;
  }
};