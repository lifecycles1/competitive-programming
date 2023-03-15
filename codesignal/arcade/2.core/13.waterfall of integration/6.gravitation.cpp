// You are given a vertical box divided into equal columns. Someone dropped several stones from its 
// top through the columns. Stones are falling straight down at a constant speed (equal for all stones) 
// while possible (i.e. while they haven't reached the ground or they are not blocked by another 
// motionless stone). Given the state of the box at some moment in time, find out which columns 
// become motionless first.

// Example

// For

// rows = ["#..##",
//         ".##.#",
//         ".#.##",
//         "....."]
// the output should be solution(rows) = [1, 4].

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
  vector<int> solution(vector<string> rows) {
    vector<int> cols(rows[0].size(),0),ans;
    for (int i = 0; i < rows[0].size(); i++) {
      bool f = false;
      for (auto r:rows) {
        if (r[i] == '#') {
          f = true;
        }
        if (f && r[i] == '.') cols[i]++;
      }
    }
    int m = *min_element(cols.begin(), cols.end());
    for (int i = 0; i < cols.size(); i++) {
      if (cols[i] == m) ans.push_back(i);
    }
    return ans;
  }
};

