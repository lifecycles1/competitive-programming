// There are a total of numCourses courses you have to take, labeled from 0 to numCourses - 1. 
// You are given an array prerequisites where prerequisites[i] = [ai, bi] indicates that you must 
// take course ai first if you want to take course bi.

// For example, the pair [0, 1] indicates that you have to take course 0 before you can take course 1.
// Prerequisites can also be indirect. If course a is a prerequisite of course b, and course b is a 
// prerequisite of course c, then course a is a prerequisite of course c.

// You are also given an array queries where queries[j] = [uj, vj]. For the jth query, you should 
// answer whether course uj is a prerequisite of course vj or not.

// Return a boolean array answer, where answer[j] is the answer to the jth query.

#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <functional>
using namespace std;

class Solution {
public:
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
      unordered_map<int, vector<int>> adj;
      for (auto& p : prerequisites) {
        adj[p[1]].push_back(p[0]);
      }

      unordered_map<int, unordered_set<int>> prereqMap;

      function<unordered_set<int>(int)> dfs = [&](int crs) {
        if (prereqMap.find(crs) == prereqMap.end()) {
          prereqMap[crs] = unordered_set<int>();
          for (int pre : adj[crs]) {
            auto s = dfs(pre);
            prereqMap[crs].insert(s.begin(), s.end());
          }
        }
        prereqMap[crs].insert(crs);
        return prereqMap[crs];
      };

      for (int crs = 0; crs < numCourses; crs++) {
        dfs(crs);
      }

      vector<bool> res;
      for (auto& q : queries) {
        res.push_back(prereqMap[q[1]].count(q[0]));
      }

      return res;
    }
};