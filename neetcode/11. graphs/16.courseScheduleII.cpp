//  There are a total of numCourses courses you have to take, labeled from 0 to numCourses - 1. 
//  You are given an array prerequisites where prerequisites[i] = [ai, bi] indicates that you must 
//  take course bi first if you want to take course ai.

// For example, the pair [0, 1], indicates that to take course 0 you have to first take course 1.
// Return the ordering of courses you should take to finish all courses. If there are many valid answers, 
// return any of them. If it is impossible to finish all courses, return an empty array.

// Courses & prerequisites, return ordering of courses to take to finish all courses
// Ex. numCourses = 2, prerequisites = [[1,0]] -> [0,1], take course 0 then 1
// All courses can be completed if there's no cycle, check for cycles
// Time: O(V + E)
// Space: O(V + E)

#include <vector>
#include <unordered_map>
#include <unordered_set>
using namespace std;

class Solution {
public:
  vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
    unordered_map<int, vector<int>> m;
    // build adjacency list of prereqs
    for (int i = 0; i < prerequisites.size(); i++) {
      m[prerequisites[i][0]].push_back(prerequisites[i][1]);
    }
    unordered_set<int> visit;
    unordered_set<int> cycle;

    vector<int> result;
    for (int course = 0; course < numCourses; course++) {
      if (!dfs(course, m, visit, cycle, result)) {
        return {};
      }
    }
    return result;
  }
private:
  // a course has 3 possible states:
  // visited -> course added to result
  // visiting -> course not added to result, but added to cycle
  // unvisited -> course not added to result or cycle
  bool dfs(int course, unordered_map<int, vector<int>>& m, unordered_set<int>& visit, unordered_set<int>& cycle, vector<int>& result) {
    if (cycle.find(course) != cycle.end()) {
      return false;
    }
    if (visit.find(course) != visit.end()) {
      return true;
    }
    cycle.insert(course);
    for (int i = 0; i < m[course].size(); i++) {
      int nextCourse = m[course][i];
      if (!dfs(nextCourse, m, visit, cycle, result)) {
        return false;
      }
    }
    cycle.erase(course);
    visit.insert(course);
    result.push_back(course);
    return true; 
  }
};