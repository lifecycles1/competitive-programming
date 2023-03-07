// Elections are in progress!

// Given an array of the numbers of votes given to each of the candidates so far, and an integer k 
// equal to the number of voters who haven't cast their vote yet, find the number of candidates who 
// still have a chance to win the election.

// The winner of the election must secure strictly more votes than any other candidate. If two or more 
// candidates receive the same (maximum) number of votes, assume there is no winner at all.

#include <vector>
using namespace std;

class Solution {
public:
  int electionsWinners(vector<int> votes, int k) {
    int max = 0, count = 0;
    for (int i = 0; i < votes.size(); i++) {
      if (votes[i] > max) {
        max = votes[i];
        count = 1;
      } else if (votes[i] == max) {
        count++;
      }
    }
    if (k == 0) {
      return count == 1 ? 1 : 0;
    }
    int result = 0;
    for (int i = 0; i < votes.size(); i++) {
      if (votes[i] + k > max) {
        result++;
      }
    }
    return result;
  }
};