// Given two strings a and b, both consisting only of lowercase English letters, 
// your task is to calculate how many strings equal to a can be constructed using 
// only letters from the string b? Each letter can be used only once and in one string only.

#include <string>
#include <vector>

class Solution {
public:
  int stringsConstruction(std::string a, std::string b) {
    std::vector<int> buckets(26, 0);
    for(auto c : b){
      buckets[c-'a']++;
    }
    int count = 0;
    while (1) {
      for(auto c : a){
        if(buckets[c-'a'] == 0)
          return count;
        buckets[c-'a']--;
      }
      count++;
    }
    return count;
  }
};