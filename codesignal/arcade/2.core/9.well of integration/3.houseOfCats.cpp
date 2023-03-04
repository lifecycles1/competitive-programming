// There are some people and cats in a house. 
// You are given the number of legs they have all together. 
// Your task is to return an array containing every possible number of people that could be in the 
// house sorted in ascending order. It's guaranteed that each person has 2 legs and each cat has 4 legs.

#include <vector>
using namespace std;

class Solution {
public:
  std::vector<int> houseOfCats(int legs) {
    vector<int> result;
    for (int i = 0; i <= legs / 2; i++) {
      if ((legs - 2 * i) % 4 == 0) {
        result.push_back(i);
      }
    }
    return result;
  }
};