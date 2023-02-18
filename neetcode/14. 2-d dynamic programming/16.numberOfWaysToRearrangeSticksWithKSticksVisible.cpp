// There are n uniquely-sized sticks whose lengths are integers from 1 to n. 
// You want to arrange the sticks such that exactly k sticks are visible from the left. 
// A stick is visible from the left if there are no longer sticks to the left of it.

// For example, if the sticks are arranged [1,3,2,5,4], then the sticks with lengths 1, 3, and 5 
// are visible from the left.
// Given n and k, return the number of such arrangements. Since the answer may be large, 
// return it modulo 109 + 7.

#include <vector>
using namespace std;

// top-down dp approach.
// Time complexity: O(n * k)
#define ll long long
class Solution {
public:
  vector<vector<ll> > dp;
  ll mod = 1e9 + 7;
  
  ll numWays(ll n, ll k) {
    if(k == 0 || k > n) return 0; // can't have no stick visible or more sticks visible than the total number of sticks
    if(n <= 2) return 1; // base condition
    
    if(dp[n][k] != -1) return dp[n][k]; // return if already calculated
    
    ll ans = 0;
    
    // select the tallest stick
    ans = (ans + numWays(n - 1, k - 1)) % mod;
    
    // select any of the n - 1 sticks that are not the tallest
    ans = (ans + ((n - 1) * numWays(n - 1, k))) % mod;
    
    return dp[n][k] = ans;
  }
  
  int rearrangeSticks(int n, int k) {
    dp = vector<vector<ll> >(n + 1, vector<ll>(k + 1, -1));
    return numWays(n, k);
  }
};

// C++ (4 ms)
// The runtime is 4 ms because our dp is global, thus re-used by all test cases.
// Inversion approach
int dp[1001][1001] = {}, mod = 1000000007;
class Solution {
public:
  int rearrangeSticks(int n, int k) {
    if (k == n)
      return 1;
    if (k > 0 && n > k && !dp[n][k])
      dp[n][k] = ((long)(n - 1) * rearrangeSticks(n - 1, k) + rearrangeSticks(n - 1, k - 1) + dp[n][k]) % mod;
    return dp[n][k];
  }
};