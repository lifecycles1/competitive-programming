// Alice has some number of cards and she wants to rearrange the cards into groups so that each 
// group is of size groupSize, and consists of groupSize consecutive cards.

// Given an integer array hand where hand[i] is the value written on the ith card and an integer 
// groupSize, return true if she can rearrange the cards, or false otherwise.

// Loop thru ordered map, for a value, check groupSize consecutive & remove
// Time: O(n log n)
// Space: O(n)

#include <vector>
#include <map>
using namespace std;

class Solution {
public:
  bool isNStraightHand(vector<int>& hand, int groupSize) {
    int n = hand.size();

    if (n % groupSize != 0) {
      return false;
    }

    // map {card value -> count}
    map<int, int> m;
    for (int i = 0; i < n; i++) {
      m[hand[i]]++;
    }

    while (!m.empty()) {
      int curr = m.begin()->first;
      for (int i = 0; i < groupSize; i++) {
        if (m[curr+i] == 0) {
          return false;
        }
        m[curr+i]--;
        if (m[curr+i] < 1) {
          m.erase(curr+i);
        }
      }
    }
    return true;
  }
};