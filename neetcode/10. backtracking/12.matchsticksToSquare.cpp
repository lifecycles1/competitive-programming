// You are given an integer array matchsticks where matchsticks[i] is the length of the ith matchstick. 
// You want to use all the matchsticks to make one square. You should not break any stick, 
// but you can link them up, and each matchstick must be used exactly one time.

// Return true if you can make this square and false otherwise.

# include <vector>
# include <numeric>
# include <algorithm>
using namespace std;

class Solution {
public:
  bool makesquare(vector<int>& matchsticks) {
    int length = accumulate(matchsticks.begin(), matchsticks.end(), 0) / 4;
    vector<int> sides(4, 0);

    if (static_cast<double>(accumulate(matchsticks.begin(), matchsticks.end(), 0)) / 4.0 != length) {
      return false;
    }

    sort(matchsticks.begin(), matchsticks.end(), greater<int>());

    return backtrack(matchsticks, sides, length, 0);
  }
private:
  bool backtrack(vector<int>& matchsticks, vector<int>& sides, int length, int index) {
    if (index == matchsticks.size()) {
      return true;
    }
    for (int j = 0; j < 4; j++) {
      if (sides[j] + matchsticks[index] <= length) {
        sides[j] += matchsticks[index];
        if (backtrack(matchsticks, sides, length, index+1)) {
          return true;
        }
        sides[j] -= matchsticks[index];
      }
    }
    return false;
  }
};