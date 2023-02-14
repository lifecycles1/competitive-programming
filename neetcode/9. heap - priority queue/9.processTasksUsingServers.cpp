// You are given two 0-indexed integer arrays servers and tasks of lengths n​​​​​​ and m​​​​​​ respectively. 
// servers[i] is the weight of the i​​​​​​th​​​​ server, and tasks[j] is the time needed to process the j​​​​​​th​​​​ task 
// in seconds.

// Tasks are assigned to the servers using a task queue. Initially, all servers are free, and the 
// queue is empty.

// At second j, the jth task is inserted into the queue (starting with the 0th task being inserted 
// at second 0). As long as there are free servers and the queue is not empty, the task in the front 
// of the queue will be assigned to a free server with the smallest weight, and in case of a tie, 
// it is assigned to a free server with the smallest index.

// If there are no free servers and the queue is not empty, we wait until a server becomes free 
// and immediately assign the next task. If multiple servers become free at the same time, then 
// multiple tasks from the queue will be assigned in order of insertion following the weight and 
// index priorities above.

// A server that is assigned task j at second t will be free again at second t + tasks[j].

// Build an array ans​​​​ of length m, where ans[j] is the index of the server the j​​​​​​th task will be 
// assigned to.

// Return the array ans​​​​.

#include <vector>
#include <queue>
#include <utility>
#include <algorithm>
using namespace std;

class Solution {
public:
  vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {
    // two min heaps, one for available server, one for unavailable
    // available = (weight, index)
    // unavailable = (timeServerBecomesFree, weight, index)
    vector<int> res(tasks.size(), 0);

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> available;
    for (int i = 0; i < servers.size(); i++) {
      available.push({ servers[i], i });
    }

    priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> unavailable;

    int t = 0;
    for (int i = 0; i < tasks.size(); i++) {
      t = max(t, i);

      if (available.empty()) {
        t = get<0>(unavailable.top());
      }
      while (!unavailable.empty() && t >= get<0>(unavailable.top())) {
        int timefree = get<0>(unavailable.top());
        int weight = get<1>(unavailable.top());
        int index = get<2>(unavailable.top());
        unavailable.pop();
        available.push({ weight, index });
      }

      int weight = available.top().first;
      int index = available.top().second;
      available.pop();
      res[i] = index;
      unavailable.push({ t + tasks[i], weight, index });
    }

    return res;
  }
};

// Time limit exceeds on this one which is almost identical as above
class Solution {
public:
  vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {
    // two min heaps, one for available server, one for unavailable
    // available = (weight, index)
    // unavailable = (timeServerBecomesFree, weight, index)
    vector<int> res(tasks.size(), 0);

    auto cmp_available = [](const auto& a, const auto& b) { return a.first > b.first; };
    priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp_available)> available(cmp_available);
    for (int i = 0; i < servers.size(); i++) {
      available.push({ servers[i], i });
    }
    auto cmp_unavailable = [](const auto& a, const auto& b) { return get<0>(a) > get<0>(b); };
    priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, decltype(cmp_unavailable)> unavailable(cmp_unavailable);

    int t = 0;
    for (int i = 0; i < tasks.size(); i++) {
      t = max(t, i);

      if (available.empty()) {
        t = get<0>(unavailable.top());
      }
      while (!unavailable.empty()) {
        t = get<0>(unavailable.top());
      }
      while (!unavailable.empty() && t >= get<0>(unavailable.top())) {
        auto [timefree, weight, index] = unavailable.top();
        unavailable.pop();
        available.push({ weight, index });
      }

      auto [weight, index] = available.top();
      available.pop();
      res[i] = index;
      unavailable.push({ t + tasks[i], weight, index });
    }

    return res;
  }
};