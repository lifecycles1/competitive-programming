// An alphanumeric ordering of strings is defined as follows: each string is considered as a 
// sequence of tokens, where each token is a letter or a number (as opposed to an isolated digit, as is 
// the case in lexicographic ordering). For example, the tokens of the string "ab01c004" are [a, b, 01, 
// c, 004]. In order to compare two strings, we'll first break them down into tokens and then compare 
// the corresponding pairs of tokens with each other (i.e. compare the first token of the first string 
// with the first token of the second string, etc).

// Here is how tokens are compared:

// If a letter is compared with another letter, the usual alphabetical order applies.
// A number is always considered less than a letter.
// When two numbers are compared, their values are compared. Leading zeros, if any, are ignored.
// If at some point one string has no more tokens left while the other one still does, the one with 
// fewer tokens is considered smaller.

// If the two strings s1 and s2 appear to be equal, consider the smallest index i such that tokens(s1)[i] 
// and tokens(s2)[i] (where tokens(s)[i] is the ith token of string s) differ only by the number of 
// leading zeros. If no such i exists, the strings are indeed equal. Otherwise, the string whose ith 
// token has more leading zeros is considered smaller.

// Here are some examples of comparing strings using alphanumeric ordering.

// "a" < "a1" < "ab"
// "ab42" < "ab000144" < "ab00144" < "ab144" < "ab000144x"
// "x11y012" < "x011y13"
// Your task is to return true if s1 is strictly less than s2, and false otherwise.

#include <string>
#include <cctype>
using namespace std;

class Solution {
public:
  bool alphanumericLess(std::string s1, std::string s2) {
    bool done = true;
    bool res = cmp(s1, s2, done, false);
    if (!done) {
        done = true;
        res = cmp(s1, s2, done, true);
    }
    return res;
  }
private:
  bool cmp(string s1, string s2, bool& done, bool checkZeroes) {
      for (int i = 0, j = 0; i < s1.size() || j < s2.size(); ) {
          if (i == s1.size() || j == s2.size()) // we've reached one of the ends
              return j != s2.size(); // whether s1 is a prefix of s2 (-> s2 has more text)
          if (isalpha(s1[i]) || isalpha(s2[j])) {
              if (s1[i] != s2[j]) // at least one the symbols is a letter
                  return isdigit(s1[i]) || s1[i] < s2[j]; // a digit or a lesser letter goes first
              i++, j++;
          } else {
              int ip = i, jp = j;
              int n1 = parseNum(s1, i);
              int n2 = parseNum(s2, j);
              if (n1 != n2)
                  return n1 < n2;
              if (checkZeroes && i-ip != j-jp)
                  return i-ip > j-jp;
          }
      }
      done = false;
      return false; // both are equal
  }

  int parseNum(string& s, int& i) {
      int n = 0;
      while (i < s.size() && isdigit(s[i]))
          n = n*10 + s[i++]-'0';
      return n;
  }
};