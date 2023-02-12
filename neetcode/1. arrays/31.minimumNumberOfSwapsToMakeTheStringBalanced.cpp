// You are given a 0-indexed string s of even length n. The string consists of exactly n / 2 
// opening brackets '[' and n / 2 closing brackets ']'.

// A string is called balanced if and only if:

// It is the empty string, or
// It can be written as AB, where both A and B are balanced strings, or
// It can be written as [C], where C is a balanced string.
// You may swap the brackets at any two indices any number of times.

// Return the minimum number of swaps to make s balanced.

// Approach: 
// Just check which '[' brackes are wrongly placed correct that bracket.
// use stack to keep track of bracket
// Time complexity : O(n)
// Space complexity: O(n)
// n is length of the string. 

#include <string>
#include <vector>
#include <stack>
using namespace std;

// 20% runtime
class Solution {
public:
  int minSwaps(string s) {
    int answer = 0;
    stack<char> stc;
    stc.push(']');
    int n = s.size();
    for (int i = 0; i < n; i++) {
      char top = stc.top();
      if (s[i] == ']') {
        // is the '[' bracket correctly placed
        // if yes then just pop
        if (top == '[') {
          stc.pop();
        } else { /* if '[' is not correctly placed then correct it (push '[') */
          stc.push('[');
          answer++;
        }
      } else {
        stc.push('['); 
      }
    }
    return answer;
  }
};

// 60% runtime
class Solution {
public:
  int minSwaps(string s) {
    int n = s.size();
    int balance = 0, swaps = 0, j=n-1;
    for(int i=0; i<n; i++) {
      if(s[i] == '[') {
        balance++;
      } else {
        balance--;
      }
      if(balance < 0) {
        while(i<j && s[j] != '[') {
          j--;
        }
        swap(s[i], s[j]);
        swaps++;
        balance = 1;
      }
    }
    return swaps;
  }
};

// 90% runtime
class Solution {
public:
  int minSwaps(string s) {
    int size = 0;
    for(char &ch : s) {
      if(ch == '[') {
        size++;
      }
      else if (size != 0) {
        size--;
      }
    }
    return (size+1)/2;
  }
};