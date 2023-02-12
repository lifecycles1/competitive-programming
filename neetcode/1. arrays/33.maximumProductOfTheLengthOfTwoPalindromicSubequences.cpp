// Given a string s, find two disjoint palindromic subsequences of s such that the product of their 
// lengths is maximized. The two subsequences are disjoint if they do not both pick a character at 
// the same index.

// Return the maximum possible product of the lengths of the two palindromic subsequences.

// A subsequence is a string that can be derived from another string by deleting some or no characters 
// without changing the order of the remaining characters. A string is palindromic if it reads the same 
// forward and backward.

 


// Approach: 
// Need to create all the disjoint subsequence and check if they are palindrome.
// keep track of maximum product 

// Time complexity : O(N*N^3)
// Space complexity: O(N)

// N is length of the string

#include <limits.h>
#include <string>
using namespace std;

class Solution {
public:
  int answer = INT_MIN;
  // function to check if the string is a palindrome
  bool isPalindrome(string &s) {
    int start = 0;
    int end = s.length() - 1;
    while (start < end) {
      if (s[start] != s[end]) {
        return false;
      }
      start++;
      end--;
    }
    return true;
  }

  // function to generate all the disjoint subsequence
  void generateAll(int idx, string& s1, string& s2, string& s) {
    if (idx >= s.length()) {
      if (isPalindrome(s1) && isPalindrome(s2)) {
        int l = s1.length() * s2.length();
        answer = max(answer, l);
      }
      return;
    }
    char c = s[idx];

    // we have three options
    // 1. Add the char to the first string
    // 2. Add the char to the second string
    // 3. Don't add the char to any string

    // add the char to the first string
    s1.push_back(c);
    generateAll(idx+1, s1, s2, s);
    s1.pop_back();

    // add the char to the second string
    s2.push_back(c);
    generateAll(idx+1, s1, s2, s);
    s2.pop_back();

    // don't add the char to any string
    generateAll(idx+1, s1, s2, s);
  }

  int maxProduct(string s) {
    string s1 = "";
    string s2 = "";
    int idx = 0;

    generateAll(idx, s1, s2, s);

    return answer;
  }
};