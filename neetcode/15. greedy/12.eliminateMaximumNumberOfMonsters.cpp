// You are playing a video game where you are defending your city from a group of n monsters. 
// You are given a 0-indexed integer array dist of size n, where dist[i] is the initial 
// distance in kilometers of the ith monster from the city.

// The monsters walk toward the city at a constant speed. The speed of each monster is 
// given to you in an integer array speed of size n, where speed[i] is the speed of the 
// ith monster in kilometers per minute.

// You have a weapon that, once fully charged, can eliminate a single monster. 
// However, the weapon takes one minute to charge.The weapon is fully charged at the very start.

// You lose when any monster reaches your city. If a monster reaches the city at the exact 
// moment the weapon is fully charged, it counts as a loss, and the game ends before you can 
// use your weapon.

// Return the maximum number of monsters that you can eliminate before you lose, or n if 
// you can eliminate all the monsters before they reach the city.

# include <vector>
# include <algorithm>
# include <queue>
using namespace std;

// sort by arrival. 85% faster
class Solution {
public:
  int eliminateMaximum(vector<int>& dist, vector<int>& speed) {
    for (int i = 0; i < dist.size(); ++i)
      dist[i] = (dist[i] - 1) / speed[i];
    sort(begin(dist), end(dist));
    for (int i = 0; i < dist.size(); ++i)
      if (i > dist[i]) {
        return i;
      }
    return dist.size();
  } 
};

// min heap. slower than sort
class Solution {
public:
  int eliminateMaximum(vector<int>& dist, vector<int>& speed) {
    for (int i = 0; i < dist.size(); ++i)
      dist[i] = (dist[i] - 1) / speed[i];
    priority_queue<int, vector<int>, greater<int>> pq(begin(dist), end(dist));
    for (int i = 0; i < dist.size() && i <= pq.top(); ++i)
      pq.pop();
    return dist.size() - pq.size();
  }   
};