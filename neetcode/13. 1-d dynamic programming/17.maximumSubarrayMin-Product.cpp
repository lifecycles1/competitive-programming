// The min-product of an array is equal to the minimum value in the array multiplied by the array's sum.

// For example, the array [3,2,5] (minimum value is 2) has a min-product of 2 * (3+2+5) = 2 * 10 = 20.
// Given an array of integers nums, return the maximum min-product of any non-empty subarray of nums. 
// Since the answer may be large, return it modulo 109 + 7.

// Note that the min-product should be maximized before performing the modulo operation. 
// Testcases are generated such that the maximum min-product without modulo will fit in 
// a 64-bit signed integer.

// A subarray is a contiguous part of an array

#include <vector>
#include <algorithm>
#include <stack>
using namespace std;

class Solution {
public:
  int maxSumMinProduct(vector<int>& n) {
    long res = 0;
    vector<long> dp(n.size() + 1), st;
    for (int i = 0; i < n.size(); ++i)
      dp[i + 1] = dp[i] + n[i];
    for (int i = 0; i <= n.size(); ++i) {
      while (!st.empty() && (i == n.size() || n[st.back()] > n[i])) {
        int j = st.back();
        st.pop_back();
        res = max(res, n[j] * (dp[i] - dp[st.empty() ? 0 : st.back() + 1]));
      }
      st.push_back(i);
    }
    return res % 1000000007;
  } 
};

// slower solution
class Solution {
public:
    #define M 1000000007
    #define ll long long
    
    int maxSumMinProduct(vector<int>& nums) {
      int n=nums.size();
      
      vector<int> prev_smallest(n); //prev. smallest ele idx for ith ele of nums
      vector<int> next_smallest(n); //next smallest ele idx for ith ele of nums
      vector<ll> prefix(n); // prefix sum to get the sum from any ith to jth idx
      prefix[0]=nums[0];
      
      //calculate prefixSum
      for(int i=1;i<n;i++){
        prefix[i]=prefix[i-1]+ nums[i];
      }
      
      stack<pair<int,int>> st1, st2; // st1->next smallest | st2->prev_smallest
      st1.push({-1,n}); 
      st2.push({-1,-1});
      
      //find next_smallest's element index for every ele of nums
      for(int i=n-1;i>=0;i--){
          while(!st1.empty() && st1.top().first>=nums[i]){
              st1.pop();
          }
          
          next_smallest[i]=st1.top().second;
          st1.push({nums[i],i});
      }
      
      //find prev_smallest's element index for every ele of nums
      for(int i=0;i<n;i++){
          while(!st2.empty() && st2.top().first>=nums[i]){
              st2.pop();
          }
          
          prev_smallest[i]=st2.top().second; //index
          st2.push({nums[i],i});
      }
      
      ll ans=INT_MIN; 
      
      //calculate max min-product
      for(int i=0;i<n;i++){
      // as we have stored the index -1 ->if no prev smallest,
      // and index n ->if no next smallest.    
          
          int left=prev_smallest[i]+1; //left index of subarray 
          int right=next_smallest[i]-1; //right index of subarray 
          
          //find subarray sum using prefix sum
          ll subArraySum= left==0 ? prefix[right] : (prefix[right]-prefix[left-1]);
          
          //take the max min-product everytime
          ans=max(ans, nums[i]*subArraySum);
      }
      
      return ans%M;
    }
};

// slower solution
class Solution {
public:
    int maxSumMinProduct(vector<int>& arr) {
        
        int n = arr.size();
        
        long long mod = 1e9 + 7;
        
        // find the prefix sum
        
        vector<long long> prefix(n, 0);
        
        prefix[0] = arr[0];
        
        for(int i = 1; i < n; i++)
        {
            prefix[i] = prefix[i - 1] + arr[i];
        }
        
        // declare a stack
        
        stack<int> st;
        
        // find the index of next smaller element on left side
        
        vector<int> left(n, -1);
        
        vector<int> right(n, n);
        
        for(int i = 0; i < n; i++)
        {
            while(st.empty() == false && arr[st.top()] >= arr[i])
            {
                st.pop();
            }
            
            if(st.empty())
            {
                left[i] = -1;
            }
            else
            {
                left[i] = st.top();
            }
            
            st.push(i);
        }
        
        // empty stack
        
        while(st.empty() == false)
        {
            st.pop();
        }
        
        // find the next smaller element on right side
        
        for(int i = n - 1; i >= 0; i--)
        {
            while(st.empty() == false && arr[st.top()] >= arr[i])
            {
                st.pop();
            }
            
            if(st.empty())
            {
                right[i] = n;
            }
            else
            {
                right[i] = st.top();
            }
            
            st.push(i);
        }
        
        // calculate maximum min-product 
       
        long long max_sum = 0;
        
        for(int i = 0; i < n; i++)
        {
            long long sum = 0;
            
            sum += prefix[right[i] - 1];
            
            if(left[i] >= 0)
            {
                sum -= prefix[left[i]];
            }
            
            sum *= arr[i];
            
            max_sum = max(max_sum, sum);
        }
        
        return max_sum % mod;
    }
};