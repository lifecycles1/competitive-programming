// There are n dominoes in a line, and we place each domino vertically upright. 
// In the beginning, we simultaneously push some of the dominoes either to the left or to the right.

// After each second, each domino that is falling to the left pushes the adjacent domino on the left. 
// Similarly, the dominoes falling to the right push their adjacent dominoes standing on the right.

// When a vertical domino has dominoes falling on it from both sides, it stays still due to the balance 
// of the forces.

// For the purposes of this question, we will consider that a falling domino expends no additional
// force to a falling or already fallen domino.

// You are given a string dominoes representing the initial state where:

// dominoes[i] = 'L', if the ith domino has been pushed to the left,
// dominoes[i] = 'R', if the ith domino has been pushed to the right, and
// dominoes[i] = '.', if the ith domino has not been pushed.
// Return a string representing the final state

// Time: O(n)
// Space: O(n)

#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
  string pushDominoes(string dominoes) {
    string res = "";
    char prev;
    int n = dominoes.size();
    int count = 1;

    vector<int> left(n, 0);
    vector<int> right(n, 0);
    for (int i = 0; i < n; i++) {
      if (dominoes[i] == 'R') {
        count = 1;
        prev = 'R';
      } else if (dominoes[i] != '.') {
        prev = dominoes[i];
      }
      if (prev == 'R' && dominoes[i] == '.') {
        right[i] = count++;
      }
    }
    prev = '.';
    for (int i = n-1; i >= 0; i--) {
      if (dominoes[i] == 'L') {
        count = 1;
        prev = 'L';
      } else if (dominoes[i] != '.') {
        prev = dominoes[i];
      }
      if (prev == 'L' && dominoes[i] == '.') {
        left[i] = count++;
      }
    }
    for (int i = 0; i < n; i++) {
      if (!left[i] && !right[i]) {
        res += dominoes[i];
      } else if (!left[i]) {
        res += 'R';
      } else if (!right[i]) {
        res += 'L';
      } else if (left[i] == right[i]) {
        res += '.';
      } else if (left[i] < right[i]) {
        res += 'L';
      } else {
        res += 'R';
      }
    }
    return res;
  }
};