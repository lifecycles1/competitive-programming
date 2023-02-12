// We are given an array asteroids of integers representing asteroids in a row.

// For each asteroid, the absolute value represents its size, and the sign represents its 
// direction (positive meaning right, negative meaning left). Each asteroid moves at the same speed.

// Find out the state of the asteroids after all collisions. If two asteroids meet, the smaller 
// one will explode. If both are the same size, both will explode. Two asteroids moving in the 
// same direction will never meet.

#include <vector>
using namespace std;

class Solution {
public:
  vector<int> asteroidCollision(vector<int> asteroids) {
    vector<int> stack;

    for (auto& a: asteroids) {
      while (!stack.empty() && a < 0 && stack.back() > 0) {
        int diff = a + stack.back();
        if (diff < 0) {
          stack.pop_back();
        } else if (diff > 0) {
          a = 0;
        } else {
          a = 0;
          stack.pop_back();
        }
      }
      if (a != 0) {
        stack.push_back(a);
      }
    }
    return stack;
  }
};