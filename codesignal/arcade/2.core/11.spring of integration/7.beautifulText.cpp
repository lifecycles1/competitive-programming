// Consider a string containing only letters and whitespaces. It is allowed to replace some 
// (possibly, none) whitespaces with newline symbols to obtain a multiline text. Call a multiline 
// text beautiful if and only if each of its lines (i.e. substrings delimited by a newline character) 
// contains an equal number of characters (only letters and whitespaces should be taken into account 
// when counting the total while newline characters shouldn't). Call the length of the line the text width.

// Given a string and some integers l and r (l ≤ r), check if it's possible to obtain a beautiful text 
// from the string with a text width that's within the range [l, r].

#include <iostream>
#include <string>

class Solution {
public:
  bool beautifulText(std::string inputString, int l, int r) {
    for (int i = l; i <= r; ++i) {
        int j = i;
        bool beautiful = true;
        for (; j < inputString.length(); j += i + 1) {
            if (inputString[j] != ' ') {
                beautiful = false;
                break;
            }
        }
        if (beautiful && j == inputString.length()) {
            return true;
        }
    }
    return false;
  }
};