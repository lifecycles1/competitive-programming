// There is a car with capacity empty seats. The vehicle only drives east 
// (i.e., it cannot turn around and drive west).

// You are given the integer capacity and an array trips where 
// trips[i] = [numPassengersi, fromi, toi] indicates that the ith trip has numPassengersi passengers 
// and the locations to pick them up and drop them off are fromi and toi respectively. 
// The locations are given as the number of kilometers due east from the car's initial location.

// Return true if it is possible to pick up and drop off all passengers for all the given trips, or 
// false otherwise.

#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
  bool carPooling(vector<vector<int>>& trips, int capacity) {
    int n = trips.size();
    vector<int> time(1001, 0);
    for (int i = 0; i < n; i++) {
      time[trips[i][1]] += trips[i][0];
      time[trips[i][2]] -= trips[i][0];
    }
    int cur = 0;
    for (int i = 0; i < 1001; i++) {
      cur += time[i];
      if (cur > capacity) return false;
    }
    return true;
  }
};

// priority queue solution
class Solution {
public:
  bool carPooling(vector<vector<int>>& trips, int capacity) {
    int n = trips.size();
    vector<int> time(1001, 0);
    for (int i = 0; i < n; i++) {
      time[trips[i][1]] += trips[i][0];
      time[trips[i][2]] -= trips[i][0];
    }
    priority_queue<int> pq;
    int cur = 0;
    for (int i = 0; i < 1001; i++) {
      cur += time[i];
      pq.push(cur);
      if (pq.top() > capacity) return false;
    }
    return true;
  }
};