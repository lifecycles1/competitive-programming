// Your Informatics teacher at school likes coming up with new ways to help you understand the material. 
// When you started studying numeral systems, he introduced his own numeral system, which 
// he's convinced will help clarify things. His numeral system has base 26, and its digits are 
// represented by English capital letters - A for 0, B for 1, and so on.

// The teacher assigned you the following numeral system exercise: given a one-digit number, 
// you should find all unordered pairs of one-digit numbers whose values add up to the number.

#include <string>
#include <vector>
using namespace std;

class Solution {
public:
  vector<string> newNumeralSystem(char number) {
    vector<string> r;
    string s = "A + ";
    s += number;
    while (s[0] <= s[4]) {
        r.push_back(s);
        s[0]++;
        s[4]--;
    }
    return r;
  }
};