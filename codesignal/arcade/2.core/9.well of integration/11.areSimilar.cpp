// Two arrays are called similar if one can be obtained from another by swapping at most one pair 
// of elements in one of the arrays.

// Given two arrays a and b, check whether they are similar.

#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
  bool areSimilar(vector<int> a, vector<int> b) {
    int count = 0;
    for (int i = 0; i < a.size(); i++) {
      if (a[i] != b[i]) {
        count++;
      }
    }
    if (count > 2) {
      return false;
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    for (int i = 0; i < a.size(); i++) {
      if (a[i] != b[i]) {
        return false;
      }
    }
    return true;
  }
};