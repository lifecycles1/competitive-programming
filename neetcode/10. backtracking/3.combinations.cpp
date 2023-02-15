// Given two integers n and k, return all possible combinations of k numbers 
// chosen from the range [1, n].

// You may return the answer in any order.

#include <vector>
using namespace std;

class Solution {
public:
  vector<vector<int>> combine(int n, int k ) {
    vector<vector<int>> res;
    vector<int> comb;
    backtrack(n, k, 1, comb, res);
    return res;
  }
private:
  void backtrack(int n, int k, int start, vector<int>& comb, vector<vector<int>>& res) {
    if (comb.size() == k) {
      res.push_back(comb);
      return;
    }
    for (int i = start; i <= n; i++) {
      comb.push_back(i);
      backtrack(n, k, i+1, comb, res);
      comb.pop_back();
    }
  }
};