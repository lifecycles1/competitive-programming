// You are given two strings s and p where p is a subsequence of s. You are also given a distinct 
// 0-indexed integer array removable containing a subset of indices of s (s is also 0-indexed).

// You want to choose an integer k (0 <= k <= removable.length) such that, after removing k 
// characters from s using the first k indices in removable, p is still a subsequence of s. 
// More formally, you will mark the character at s[removable[i]] for each 0 <= i < k, then 
// remove all marked characters and check if p is still a subsequence.

// Return the maximum k you can choose such that p is still a subsequence of s after the removals.

// A subsequence of a string is a new string generated from the original string with some characters 
// (can be none) deleted without changing the relative order of the remaining characters.

#include <vector>
#include <string>
using namespace std;

class Solution {
public:
  bool isSubSequence(string str1, string str2){
    int j = 0,m=str1.size();
    int n = str2.size();
    for (int i = 0; i < n && j < m; i++) {
      if (str1[j] == str2[i]) {
        j++;
      }
    }
    return (j == m);
  }
  int maximumRemovals(string s, string p, vector<int>& removable) {
    string copy = s;
    int left = 0, right =removable.size();
    while (left <= right) {
      int mid = (left+right)/2;
      for(int i = 0; i < mid; i++) {
        copy[removable[i]] = '*'; // to keep of the characters removed they will be marked as * 
      }
      //if p is subsequence of string after mid number of removals then we should look for if it's possible to remove more characters 
      if (isSubSequence(p,copy)) {
        left = mid+1;
      //if p is not a subsequence of string it means that we have certainly removed more characters from string 
      //so we must decrease our size of removal characters and hence we  add all characters we removed earlier.
      } else {
        for(int i=0;i<mid;i++) {
          copy[removable[i]] = s[removable[i]];
        }
        right = mid-1;
      }
    }
    return right;
  }
};