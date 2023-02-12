// Given a string s consisting of words and spaces, return the length of the last word in the string.

// A word is a maximal substring consisting of non-space characters only.

// Traverse from end to the first whitespace character and count the number of letters.
// Return the count as our pointer hits the whitespace character.
// Time complexity: O(n)
// Space complexity: O(1)

#include <string>
using namespace std;

class Solution {
public:
  int lengthOfLastWord(string s) {
    int n = s.length();

    int ptr = n-1;
    while (ptr >= 0 && s[ptr] == ' ') { /* Skip the trailing whitespaces */
      ptr--; 
    }
    int len = 0;
    while (ptr >= 0 && s[ptr--] != ' ') { /* Counting the letters in the last word */
      len++;
    }
    return len;
  }
};