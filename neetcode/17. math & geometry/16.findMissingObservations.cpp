// You have observations of n + m 6-sided dice rolls with each face numbered from 1 to 6. 
// n of the observations went missing, and you only have the observations of m rolls. 
// Fortunately, you have also calculated the average value of the n + m rolls.

// You are given an integer array rolls of length m where rolls[i] is the value of the ith observation. 
// You are also given the two integers mean and n.

// Return an array of length n containing the missing observations such that the average 
// value of the n + m rolls is exactly mean. If there are multiple valid answers, 
// return any of them. If no such array exists, return an empty array.

// The average value of a set of k numbers is the sum of the numbers divided by k.

// Note that mean is an integer, so the sum of the n + m rolls should be divisible by n + m.

#include <vector>
#include <numeric>
using namespace std;

class Solution {
public:
  vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
    int m = rolls.size();
    int sum = 0;
    for (int i = 0; i < m; i++) {
      sum += rolls[i];
    }
    int total = (m + n) * mean;
    int missingSum = total - sum;
    if (missingSum < n || missingSum > 6 * n) {
      return {};
    }
    vector<int> res;
    int q = missingSum / n;
    int r = missingSum % n;
    for (int i = 0; i < n; i++) {
      res.push_back(q);
    }
    for (int i = 0; i < r; i++) {
      res[i]++;
    }
    return res;
  }
};

class Solution {
public:
  vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
    int curSum = accumulate(rolls.begin(), rolls.end(), 0), m = rolls.size();
    int missingSum = mean * (n + m) - curSum;
    if (missingSum < n || missingSum > 6*n) return {};
    
    int part = missingSum / n, rem = missingSum % n;
    vector<int> ans(n, part);
    for (int i = 0; i < rem; ++i) 
      ++ans[i];
    return ans;
  }
};