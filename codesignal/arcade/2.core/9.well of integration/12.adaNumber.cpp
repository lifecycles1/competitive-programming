// Consider two following representations of a non-negative integer:

// A simple decimal integer, constructed of a non-empty sequence of digits from 0 to 9;
// An integer with at least one digit in a base from 2 to 16 (inclusive), 
// enclosed between # characters, and preceded by the base, which can only be a number between 
// 2 and 16 in the first representation. For digits from 10 to 15 characters a, b, ..., f 
// and A, B, ..., F are used.
// Additionally, both representations may contain underscore (_) characters; they are used only 
// as separators for improving legibility of numbers and can be ignored while processing a number.

// Your task is to determine whether the given string is a valid integer representation.

#include <regex>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    bool adaNumber(string line) {
      line.erase(remove(begin(line), end(line), '_'), end(line));
      transform(begin(line), end(line), begin(line), ::tolower);

      smatch m;
      int base = 10;
      return regex_match(line, m, regex("([0-9]+)(#[0-9a-f]+#|)"))
          && (!m.length(2) || (base = stoi(m.str(1))) >= 2 && base <= 16)
          && m.str(2).find_first_not_of("fedcba9876543210#" + 16 - base) == -1;
    }
};