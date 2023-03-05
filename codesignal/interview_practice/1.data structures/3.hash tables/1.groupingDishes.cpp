// You are given a list dishes, where each element consists of a list of strings beginning 
// with the name of the dish, followed by all the ingredients used in preparing it. 
// You want to group the dishes by ingredients, so that for each ingredient you'll be able to 
//     find all the dishes that contain it (if there are at least 2 such dishes).

// Return an array where each element is a list beginning with the ingredient name, 
// followed by the names of all the dishes that contain this ingredient. 
// The dishes inside each list should be sorted alphabetically, and the result array should be 
// sorted alphabetically by the names of the ingredients.

#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
using namespace std;

class Solution {
public:
  vector<vector<string>> groupingDishes(vector<vector<string>> dishes) {
    vector<vector<string>> result;
    map<string, vector<string>> m;
    for (int i = 0; i < dishes.size(); i++) {
      for (int j = 1; j < dishes[i].size(); j++) {
        m[dishes[i][j]].push_back(dishes[i][0]);
      }
    }
    for (auto it = m.begin(); it != m.end(); it++) {
      if (it->second.size() > 1) {
        sort(it->second.begin(), it->second.end());
        vector<string> temp;
        temp.push_back(it->first);
        for (int i = 0; i < it->second.size(); i++) {
          temp.push_back(it->second[i]);
        }
        result.push_back(temp);
      }
    }
    return result;
  }
};