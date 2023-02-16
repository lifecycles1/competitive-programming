// You have a lock in front of you with 4 circular wheels. 
// Each wheel has 10 slots: '0', '1', '2', '3', '4', '5', '6', '7', '8', '9'. 
// The wheels can rotate freely and wrap around: for example we can turn 
// '9' to be '0', or '0' to be '9'. Each move consists of turning one wheel one slot.

// The lock initially starts at '0000', a string representing the state of the 4 wheels.

// You are given a list of deadends dead ends, meaning if the lock displays any of these codes, 
// the wheels of the lock will stop turning and you will be unable to open it.

// Given a target representing the value of the wheels that will unlock the lock, return the 
// minimum total number of turns required to open the lock, or -1 if it is impossible.

#include <vector>
#include <string>
#include <queue>
#include <unordered_set>
#include <deque>
#include <utility>

// random indian girl - faster solution
class Solution {
public:
  int openLock(std::vector<std::string>& deadends, std::string target) {
    std::queue<std::string> bfs;
    std::unordered_set<std::string> hash(deadends.begin(), deadends.end());
    std::unordered_set<std::string> visited;
    
    if (hash.find("0000") != hash.end())
        return -1;
    
    int depth = 0;
    bfs.push("0000");
    visited.insert("0000");
    
    while(!bfs.empty()) {
      int siz=bfs.size();
      
      for(int k=0;k<siz;k++) {
        std::string current_stage = bfs.front();
        bfs.pop();

        if (current_stage == target) {
          return depth;
        }

        for (int i = 0; i < 4; i++) {
          char temp = current_stage[i];
          current_stage[i] = temp == '9' ? '0' : temp + 1;
          if (hash.find(current_stage) == hash.end() && visited.find(current_stage)==visited.end()) {
            bfs.push(current_stage);
            visited.insert(current_stage);
          }

          current_stage[i] = temp == '0' ? '9' : temp - 1;
          if (hash.find(current_stage) == hash.end() && visited.find(current_stage)==visited.end()) {
            bfs.push(current_stage);
            visited.insert(current_stage);
          }
          current_stage[i] = temp;
        }
      }
      
      depth++;
    }
    return -1;
  }
};


// neetcode - similar but slower solution
class Solution {
public:
  int openLock(std::vector<std::string>& deadends, std::string target) {
    std::unordered_set<std::string> dead_set(deadends.begin(), deadends.end());
    if (dead_set.find("0000") != dead_set.end()) {
      return -1;
    }

    auto children = [&](std::string wheel) -> std::vector<std::string> {
      std::vector<std::string> res;
      for (int i = 0; i < 4; i++) {
        std::string digit(1, ((wheel[i] - '0' + 1) % 10) + '0');
        res.push_back(wheel.substr(0, i) + digit + wheel.substr(i + 1));
        digit = std::string(1, ((wheel[i] - '0' + 10 - 1) % 10) + '0');
        res.push_back(wheel.substr(0, i) + digit + wheel.substr(i + 1));
      }
      return res;
    };

    std::deque<std::pair<std::string, int>> q;
    std::unordered_set<std::string> visited;
    q.push_back(std::make_pair("0000", 0)); // [wheel, turns]
    while (!q.empty()) {
      auto [wheel, turns] = q.front();
      q.pop_front();
      if (wheel == target) {
        return turns;
      }
      for (auto child : children(wheel)) {
        if (visited.find(child) == visited.end() && dead_set.find(child) == dead_set.end()) {
          visited.insert(child);
          q.push_back(std::make_pair(child, turns + 1));
        }
      }
    }
    return -1;
  }
};
