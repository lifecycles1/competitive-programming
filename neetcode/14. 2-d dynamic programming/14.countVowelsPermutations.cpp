// Given an integer n, your task is to count how many strings of length n can be formed under 
// the following rules:

// Each character is a lower case vowel ('a', 'e', 'i', 'o', 'u')
// Each vowel 'a' may only be followed by an 'e'.
// Each vowel 'e' may only be followed by an 'a' or an 'i'.
// Each vowel 'i' may not be followed by another 'i'.
// Each vowel 'o' may only be followed by an 'i' or a 'u'.
// Each vowel 'u' may only be followed by an 'a'.
// Since the answer may be too large, return it modulo 10^9 + 7.

#include <vector>
using namespace std;

// Bottom-up: With inversed relationships
static vector<vector<int>> relation={{1,2,4},{0,2},{1,3},{2},{2,3}};  //Relationships(can be followed after) of each vowel with others
class Solution {
public:
  int countVowelPermutation(int n) {
    int MOD=1e9+7;
    vector<long long> vowels(5,1),vowels_copy;      //When N=1 all vowels are used once to for 1 letter strings
    long long result=0;
    while(--n) {
      vowels_copy=vowels;
      for(int i=0;i<5;i++) {                    //Characters 'a' 'e' 'i' 'o' 'u'.
        vowels[i]=0;
        for(int &r:relation[i])
          vowels[i]+=vowels_copy[r],vowels[i]%=MOD;  //Add the strings that end with characters that can have 'i' after them.
      }
    }
    for(long long &i:vowels)
      result+=i,result%=MOD;
    return result;
  }
};

// Complexity
// Space: O(1)
// Time: O(n)
// Top-Down (Recursive):
static vector<vector<int>> relation={{1},{0,2},{0,1,3,4},{2,4},{0}};  //Relationships(followed by) of each vowel with others
class Solution {
public:
  int MOD=1e9+7;
  vector<vector<int>> memo;
  int dp(int n,int v) {                       //'v' represents the vowel
    if(n==1)
      return 1;
    if(memo[n][v]!=-1)
      return memo[n][v];
    memo[n][v]=0;
    for(int &i:relation[v])
      memo[n][v]+=dp(n-1,i),memo[n][v]%=MOD;
    return memo[n][v];
  }
  int countVowelPermutation(int n) {
    int result=0;
    memo.resize(n+1,vector<int>(5,-1));
    for(int i=0;i<5;i++)
      result+=dp(n,i),result%=MOD;
    return result;
  }
};

// Complexity
// Space: O(n)
// Time: O(n)
// Matrix Exponentiation:
// This problem basically boils down to number of paths of length N in a directed graph.

//Matrix exponentiation.
class Solution {
public:
  int MOD=1e9+7;
  vector<vector<int>> Multiply(vector<vector<int>> &l,vector<vector<int>> &r) { //Multiply two matrices applying MOD.
    vector<vector<int>> result(l.size(),vector<int>(r[0].size(),0));
    for(int i=0;i<l.size();i++)
      for(int j=0;j<r[0].size();j++)
        for(int k=0;k<l[0].size();k++)
          result[i][j]+=(long long)l[i][k]*r[k][j]%MOD,result[i][j]%=MOD;
    return result;
  }
  int countVowelPermutation(int n) {
    vector<vector<int>> M={ {0,1,0,0,0},      //Adjacency matrix of graph of the problem.
                            {1,0,1,0,0},
                            {1,1,0,1,1},
                            {0,0,1,0,1},
                            {1,0,0,0,0}},result(5,vector<int>(5));
    for(int i=0;i<5;i++)   //Create identity Matrix.
      result[i][i]=1;
    int sum=0;
    n--;
    while(n) {   //log(n) Multiplication.
      if(n&1)
        result=Multiply(M,result);
      n>>=1;
      M=Multiply(M,M);
    }
    for(vector<int> &i:result)          //Result holds M^(N-1).
      for(int &j:i)
        sum+=j,sum%=MOD;
    return sum;
  }
};