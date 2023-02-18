// A triplet is an array of three integers. You are given a 2D integer array triplets, where 
// triplets[i] = [ai, bi, ci] describes the ith triplet. You are also given an integer array 
// target = [x, y, z] that describes the triplet you want to obtain.

// To obtain target, you may apply the following operation on triplets any number of times (possibly zero):

// Choose two indices (0-indexed) i and j (i != j) and update triplets[j] to become 
// [max(ai, aj), max(bi, bj), max(ci, cj)].
// For example, if triplets[i] = [2, 5, 3] and triplets[j] = [1, 7, 5], triplets[j] will be 
// updated to [max(2, 1), max(5, 7), max(3, 5)] = [2, 7, 5].
// Return true if it is possible to obtain the target triplet [x, y, z] as an element of triplets, 
// or false otherwise.

// Skip all "bad" triplets (can never become target), if match add to "good" set
// Time: O(n)
// Space: O(1)

#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
  bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
    unordered_set<int> s;

    for (int i = 0; i < triplets.size(); i++) {
      if (triplets[i][0] > target[0] || triplets[i][1] > target[1] || triplets[i][2] > target[2]) {
        continue;
      }

      for (int j = 0; j < 3; j++) {
        if (triplets[i][j] == target[j]) {
          s.insert(j);
        }
      }
    }
    return s.size() == 3;
  }
};