// You're a crossword fanatic, and have finally decided to try and create your own. 
// However, you also love symmetry and good design, so you come up with a set of rules they 
// should follow:

// the crossword must contain exactly four words;
// these four words should form four pairwise intersections;
// all words must be written either left-to-right or top-to-bottom;
// the area of the rectangle formed by empty cells inside the intersections isn't equal to zero.
// Given 4 words, find the number of ways to make a crossword following the above-described rules. 
// Note that two crosswords which differ by rotation are considered different

#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
int process(vector<string>& w) {
  int ans = 0;
  for (int i = 0; i < w[0].length(); i++) {
    for (int j = 0; j < w[1].length(); j++) {
      if (w[0][i] == w[1][j]) {
        for (int k = j+2; k < w[1].length(); k++) {
          for (int h = 0; h < w[2].length(); h++) {
            if (w[1][k] == w[2][h]) {
              for (int x = h+2; x < w[2].length(); x++) {
                for (int y = 0; y < w[3].length(); y++) {
                  if (w[2][x] == w[3][y]) {
                    int width = k - j;
                    int height = x - h;
                    if (y - width >= 0 && i + height < w[0].length()) {
                      if (w[3][y - width] == w[0][i + height]) {
                        ans++;
                      }
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
  }
  return ans;
}

  int crosswordFormation(std::vector<std::string> w) {
    sort(w.begin(), w.end());
    int cnt = 0;
    do {
      cnt += process(w);
    } while (next_permutation(w.begin(), w.end()));
    
    return cnt;
  }
};

