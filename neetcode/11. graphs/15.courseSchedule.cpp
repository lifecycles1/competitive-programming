// There are a total of numCourses courses you have to take, labeled from 0 to numCourses - 1. 
// You are given an array prerequisites where prerequisites[i] = [ai, bi] indicates that you must 
// take course bi first if you want to take course ai.

// For example, the pair [0, 1], indicates that to take course 0 you have to first take course 1.
// Return true if you can finish all courses. Otherwise, return false.

// Courses & prerequisites, return true if can finish all courses
// Ex. numCourses = 2, prerequisites = [[1,0]] -> true
// All courses can be completed if there's no cycle (visit already visited)
// Time: O(V + E)
// Space: O(V + E)

#include <vector>
#include <unordered_map>
#include <unordered_set>
using namespace std;

class Solution {
public:
  bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
    // map each course to prereq list
    unordered_map<int, vector<int>> m;
    for (int i = 0; i < prerequisites.size(); i++) {
      m[prerequisites[i][0]].push_back(prerequisites[i][1]);
    }
    // all courses along current DFS path
    unordered_set<int> visited;

    for (int course = 0; course < numCourses; course++) {
      if (!dfs(course, m, visited)) {
        return false;
      }
    }
    return true;
  }
private:
  bool dfs(int course, unordered_map<int, vector<int>>& m, unordered_set<int>& visited) {
    if (visited.find(course) != visited.end()) {
      return false;
    }
    if (m[course].empty()) {
      return true;
    }
    visited.insert(course);
    for (int i = 0; i < m[course].size(); i++) {
      int nextCourse = m[course][i];
      if (!dfs(nextCourse, m, visited)) {
        return false;
      }
    }
    m[course].clear();
    visited.erase(course);
    return true;
  }
};