// You are given an array of integers stones where stones[i] is the weight of the ith stone.

// We are playing a game with the stones. On each turn, we choose the heaviest two stones and 
// smash them together. Suppose the heaviest two stones have weights x and y with x <= y. The result 
// of this smash is:

// If x == y, both stones are destroyed, and
// If x != y, the stone of weight x is destroyed, and the stone of weight y has new weight y - x.
// At the end of the game, there is at most one stone left.

// Return the weight of the last remaining stone. If there are no stones left, return 0.

// Given array of stones to smash, return smallest possible weight of last stone
// If x == y both stones destroyed, if x != y stone x destroyed, stone y = y - x
// Ex. stones = [2,7,4,1,8,1] -> 1, [2,4,1,1,1], [2,1,1,1], [1,1,1], [1]

// Max heap, pop 2 biggest, push back difference until no more 2 elements left

// Time: O(n log n)
// Space: O(n)

#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
  int lastStoneWeight(vector<int>& stones) {
    priority_queue<int> pq;
    for (int i = 0; i < stones.size(); i++) {
      pq.push(stones[i]);
    }

    while (pq.size() > 1) {
      int y = pq.top();
      pq.pop();
      int x = pq.top();
      pq.pop();
      if (y > x) {
        pq.push(y - x);
      }
    }
    if (pq.empty()) {
      return 0;
    }
    return pq.top();
  }
};