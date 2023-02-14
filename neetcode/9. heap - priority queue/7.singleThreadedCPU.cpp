// # You are given n​​​​​​ tasks labeled from 0 to n - 1 represented by a 2D integer array tasks, where 
// # tasks[i] = [enqueueTimei, processingTimei] means that the i​​​​​​th​​​​ task will be available to process at enqueueTimei and will take 
// # processingTimei to finish processing.

// # You have a single-threaded CPU that can process at most one task at a time and will act in the following way:

// # If the CPU is idle and there are no available tasks to process, the CPU remains idle.
// # If the CPU is idle and there are available tasks, the CPU will choose the one with the shortest processing time. 
// # If multiple tasks have the same shortest processing time, it will choose the task with the smallest index.
// # Once a task is started, the CPU will process the entire task without stopping.
// # The CPU can finish a task then start a new one instantly.
// # Return the order in which the CPU will process the tasks.

#include <vector>
#include <queue>
#include <utility>
#include <algorithm>

class Solution {
public:
  std::vector<int> getOrder(std::vector<std::vector<int>>& tasks) {
    std::vector<std::vector<int>> v;
    for (int i = 0; i < tasks.size(); i++) {
      v.push_back({tasks[i][0], tasks[i][1], i});
    }
    sort(v.begin(), v.end(), [](const auto& a, const auto& b) {
      return a[0] < b[0];
    });

    std::vector<int> res;
    std::priority_queue<std::vector<int>, std::vector<std::vector<int>>, std::greater<std::vector<int>>> minHeap;
    int i = 0;
    long long time = v[0][0];
    while (!minHeap.empty() || i < v.size()) {
      while (i < v.size() && time >= v[i][0]) {
        minHeap.push({v[i][1], v[i][2]});
        i++;
      }
      if (minHeap.empty()) {
        time = v[i][0];
      } else {
        auto processedTime = minHeap.top();
        minHeap.pop();
        time += processedTime[0];
        res.push_back(processedTime[1]);
      }
    }
    return res;
  }
};

// Time: O(NlogN)
// Space: O(N)
class Solution {
  typedef std::pair<int, int> T; // processing time, index
public:
  std::vector<int> getOrder(std::vector<std::vector<int>>& A) {
    std::priority_queue<T, std::vector<T>, std::greater<>> pq; // min heap of tasks, sorted first by processing time then by index.
    long N = A.size(), time = 0, i = 0; // `time` is the current time, `i` is the read pointer
    for (int i = 0; i < N; ++i) A[i].push_back(i); // append the index to each task
    sort(begin(A), end(A)); // sort the input array so that we can take the tasks of small enqueueTime first
    std::vector<int> ans;
    while (i < N || pq.size()) { // stop the loop when we exhausted the input array and the tasks in the heap.
      if (pq.empty()) {
        time = std::max(time, (long)A[i][0]); // nothing in the heap? try updating the current time using the processing time of the next task in array
      }
      while (i < N && time >= A[i][0]) { // push all the tasks in the array whose enqueueTime <= currentTime into the heap
        pq.emplace(A[i][1], A[i][2]);
        ++i;
      }
      auto [pro, index] = pq.top();
      pq.pop();
      time += pro; // handle this task and increase the current time by the processingTime
      ans.push_back(index);
    }
    return ans;
  }
};