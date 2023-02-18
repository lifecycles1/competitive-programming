// The alternating sum of a 0-indexed array is defined as the sum of the elements at even 
// indices minus the sum of the elements at odd indices.

// For example, the alternating sum of [4,2,5,3] is (4 + 5) - (2 + 3) = 4.
// Given an array nums, return the maximum alternating sum of any subsequence of nums 
// (after reindexing the elements of the subsequence).

// A subsequence of an array is a new array generated from the original array by deleting some 
// elements (possibly none) without changing the remaining elements' relative order. For example, 
// [2,7,4] is a subsequence of [4,2,3,7,2,1,4] (the underlined elements), while [2,4,2] is not.

# include <vector>
# include <algorithm>
using namespace std;

// 65% faster
class Solution {
  typedef long long LL;
public:
  long long maxAlternatingSum(vector<int>& A) {
    LL N = A.size(), dp[2] = {};
    for (int i = 0; i < N; ++i) {
      LL next[2] = {};
      next[0] = max(dp[1] + A[i], dp[0]);
      next[1] = max(dp[0] - A[i], dp[1]);
      swap(next, dp);
    }
    return dp[0];
  }
};

// faster solution 85%
class Solution {
public:
  long long maxAlternatingSum(vector<int>& A) {
    long long odd = 0, even = 0;
    for (int& a: A)
      even = max(even, odd + a),
      odd = even - a;
    return even;
  }
};

// faster solution 95%
class Solution {
public:
    long long maxAlternatingSum(vector<int>& A) {
    long res = A[0];
    for (int i = 1; i < A.size(); ++i)
      res += max(A[i] - A[i-1], 0);
    return res;
  }
};